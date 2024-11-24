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

t_shell	*shell_struct(t_shell *shell, int flag)
{
	static t_shell	*ptr;

	if (flag)
		return (ptr);
	ptr = shell;
	return (ptr);
}

void	sigint_heredoc_handler(int sig)
{
	const t_shell	*shell = shell_struct(NULL, 1);

	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		close(shell->fd);
		free_env_lst(shell->envp);
		free_shell((t_shell *)shell);
		exit_code(130);
		exit(130);
	}
}

void	heredoc_signal(void)
{
	signal(SIGINT, sigint_heredoc_handler);
	signal(SIGQUIT, SIG_IGN);
}
