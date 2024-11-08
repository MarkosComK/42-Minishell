/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:38:33 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 11:43:45 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	sigint_heredoc_handler(int sig)
{
	t_shell	*shell = shell_struct(NULL, 1);
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		close(shell->fd);
		free_env_lst(shell->envp);
		free_shell(shell);
		exit(130);
	}
}

void	heredoc_signal(void)
{
	signal(SIGINT, sigint_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
}
