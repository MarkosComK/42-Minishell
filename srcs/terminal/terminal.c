/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:29 by hluiz-ma         ###   ########.fr       */
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
void	terminal(t_shell *shell, char **envp)
{
	start_shell(shell);
	handle_signals();
	shell_input(shell);
	shell->input = readline(shell->cwd);
	if (shell->input && shell->input[0] != '\0')
		add_history(shell->input);
	if (shell->input && input_validation(shell))
	{
		free_shell(shell);
		terminal(shell, envp);
	}
	if (shell->input == NULL || !ft_strcmp(shell->trim_input, "exit"))
	{
		free_shell(shell);
		return ;
	}
	lexer(shell, shell->trim_input);
	shell->envp_arr = env_arr(shell);
	shell->path = path_list(shell, envp);
	shell->root = build_tree(shell, shell->token_lst);
	print_token_lst(shell->token_lst);
	print_bst(shell->root, 5);
	set_main_signals();
	handle_heredoc(shell, shell->root);
	exec_processes(shell);
	free_shell(shell);
	terminal(shell, envp);
}

void	free_shell(t_shell *shell)
{
	t_list	*tmp;
	t_token	*token;
	int		i;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		token = (t_token *) shell->token_lst->content;
		free(token->value);
		free(shell->token_lst->content);
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
	i = 0;
	if (shell->envp_arr)
	{
		while (shell->envp_arr[i])
		{
			free(shell->envp_arr[i]);
			i++;
		}
		free(shell->envp_arr);
	}
	while (shell->path)
	{
		tmp = shell->path->next;
		free(shell->path->content);
		free(shell->path);
		shell->path = tmp;
	}
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->root)
		free_bst(shell->root);
	if (shell->cmd_path)
		free(shell->cmd_path);
	if (shell->cwd)
		free(shell->cwd);
	finish_shell(shell);
}
