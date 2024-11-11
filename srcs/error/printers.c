/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:36:29 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 12:06:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	syntax_error_msg(char *str)
{
	static bool	message_printed;

	message_printed = false;
	if (!message_printed)
	{
		ft_putstr_fd(SYNTAX_ERROR, 2);
		if (str)
			ft_putendl_fd(str, 2);
		message_printed = true;
	}
	else
		message_printed = false;
	return (true);
}

void	path_message(t_shell *shell, char *path, char *error_msg)
{
	ft_putstr_fd(MINISHELL " " DEFAULT, 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(error_msg, 2);
	free_env_lst(shell->envp);
	free_shell(shell);
}

void	cmd_message(t_shell *shell, char *cmd, char *error_msg)
{
	ft_putstr_fd(MINISHELL " " DEFAULT, 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(error_msg, 2);
	free_shell(shell);
}
