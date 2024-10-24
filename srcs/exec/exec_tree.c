/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 04:09:41 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
void	exec_tree(t_shell *shell, void *root)
{
	char	*cmd_path = find_cmd_path(shell->path, ((t_exec *)root)->command);
	printf("cmd_path: %s\n", cmd_path);
	if (execve(cmd_path, ((t_exec *)root)->argv, NULL) == -1)
	{
		free_shell(shell);
		exit(1);
	}
}
*/

void	exec_tree(t_shell *shell, void *root)
{
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

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == 0)
		handle_pid1(shell, pipefd, pipe_node);
	pid2 = fork();
	if (pid2 == 0)
		handle_pid2(shell, pipefd, pipe_node);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_shell(shell);
	exit(0);
}

void	exec_node(t_shell *shell, t_exec *exec_node)
{
	char	*cmd_path;
	int		i;
	int		fd;

	i = 0;
	if (exec_node->infiles)
	{
		while (exec_node->infiles[i])
		{
			fd = open(exec_node->infiles[i], O_RDONLY);
			if (fd < 0)
			{
				exit_failure(shell, "INFILE FAILURE\n");
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			i++;
		}
	}
	i = 0;
	if (exec_node->outfiles)
	{
		while (exec_node->outfiles[i])
		{
			fd = open(exec_node->outfiles[i], O_RDWR | O_CREAT, 0644);
			if (fd < 0)
			{
				exit_failure(shell, "OUTF FAILURE\n");
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			i++;
		}
	}
	cmd_path = find_cmd_path(shell->path, exec_node->command);
	if (!cmd_path)
	{
		exit_failure(shell, "CMD NOT FOUND\n");
	}
	if (execve(cmd_path, exec_node->argv, shell->envp_arr) == -1)
	{
		exec_failure(shell);
	}
}
