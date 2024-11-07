/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:06 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	run_heredoc(t_shell *shell, t_inf *infile, int fd)
{
	char	*line;

	if (fd < 0)
		infile_failure(shell, infile->eof);
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
	pid_t	pid;
	int		status;

	infiles = exec->infiles;
	status = 0;
	(void) shell;
	while (infiles)
	{
		inf = (t_inf *)infiles->content;
		if (inf->type == HERE)
		{
			fd = open(inf->eof, O_RDWR | O_CREAT | O_APPEND, 0644);
			pid = fork();
			if (pid == 0)
			{
				run_heredoc(shell, inf, fd);
				close(fd);
				free_env_lst(shell->envp);
				free_shell(shell);
				exit(0);
			}
			waitpid(pid, &status, 0);
			close(fd);
		}
		infiles = infiles->next;
	}
}

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
