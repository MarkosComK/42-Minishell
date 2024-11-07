/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 15:59:48 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


int	run_heredoc(t_shell *shell, t_inf *infile, int fd)
{
	char	*line;

	if (fd < 0)
		infile_failure(shell, infile->eof);
	dprintf(2, B_RED"START_HERED\n"DEFAULT);
	dprintf(2, B_RED"EOF_IS:%s\n"DEFAULT, infile->eof);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !ft_strcmp(line, infile->eof))
		{
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	return (fd);
}

void	set_exec(t_shell *shell, t_exec *exec)
{
	t_list	*infiles;
	t_inf	*inf;
	int		fd;

	infiles = exec->infiles;
	(void) shell;
	while (infiles)
	{
		inf = (t_inf *)exec->infiles->content;
		if (inf->type == HERE)
		{
			fd = open(inf->eof, O_RDWR | O_CREAT | O_APPEND, 0644);
			pid_t	pid;
			int		status = 0;
			if ((pid = fork()) == 0)
			{
				run_heredoc(shell, inf, fd);
				close(fd);
				exit(0);
			}
			waitpid(pid, &status, 0);
			close(fd);
		}
		infiles = infiles->next;
	}
}

void	handle_heredoc(t_shell *shell, void *root);

void	traverse_pipe(t_shell *shell, t_pipe *pipe)
{
	if (pipe->left)
		handle_heredoc(shell, pipe->left);
	if (pipe->right)
		handle_heredoc(shell, pipe->right);
}

void	handle_heredoc(t_shell *shell, void *root)
{
	if (((t_node *)root)->type == N_PIPE)
		traverse_pipe(shell, root);
	else if (((t_node *)root)->type == N_EXEC)
		set_exec(shell, root);
}


void	exec_tree(t_shell *shell, void *root)
{
		handle_heredoc(shell, root);
	if (((t_node *)root)->type == N_PIPE)
		exec_pipe(shell, root);
	else if (((t_node *)root)->type == N_EXEC)
		exec_node(shell, root);
}

void	exec_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	status = 0;
	pid1 = fork();
	if (pid1 == 0)
	{
		handle_pid1(shell, pipefd, pipe_node);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		handle_pid2(shell, pipefd, pipe_node);
		exit(0);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(pid2, &status, 0);
	waitpid(pid1, &status, 0);
	exit_status(status);
	free_env_lst(shell->envp);
	free_shell(shell);
	exit(exit_code(-1));
}

//muitas coisas na vida sao estranhas, mas nada vencera as validacoes
//pra minha menssagem de erro.
void	exec_node(t_shell *shell, t_exec *exec_node)
{
	int		ret;

	handle_infiles(shell, exec_node);
	handle_outfiles(shell, exec_node);
	if (exec_node->command && is_builtin(exec_node->command))
	{
		ret = exec_builtin(shell, exec_node);
		free_env_lst(shell->envp);
		free_shell(shell);
		exit(ret);
		return ;
	}
	set_fork1_signal();
	shell->cmd_path = find_cmd_path(shell, shell->path, exec_node->command);
	if (exec_node->argv)
		is_directory(shell, exec_node->argv[0]);
	if (execve(shell->cmd_path, exec_node->argv, shell->envp_arr) < 0)
	{
		free_env_lst(shell->envp);
		exec_failure(shell, shell->cmd_path, exec_node->argv);
	}
}
