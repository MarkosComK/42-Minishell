
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:37:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:44:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_failure(t_shell *shell, char *function)
{
	free_shell(shell);
	perror(RED"malloc error:");
	perror(function);
	perror(DEFAULT);
	perror("\n");
	exit(1);
}

void	exec_failure(t_shell *shell)
{
	free_shell(shell);
	perror(RED"execve:");
	perror(DEFAULT"\n");
	exit(1);
}
