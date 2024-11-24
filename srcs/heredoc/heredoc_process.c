/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:19:25 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 17:21:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	heredoc_process(t_shell *shell, t_inf *inf, int fd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		heredoc_signal();
		shell->fd = fd;
		run_heredoc(shell, inf, fd);
		close(fd);
		free_env_lst(shell->envp);
		free_shell(shell);
		exit_code(0);
		exit(exit_code(-1));
	}
	waitpid(pid, &status, 0);
	exit_status(status);
	close(fd);
}
