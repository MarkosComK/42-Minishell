
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
	if (!function)
	{
		perror(RED"EXECVE FAIL"DEFAULT);
		exit(1);
	}
	perror(RED"malloc error:");
	perror(function);
	perror(DEFAULT);
	perror("\n");
	exit(1);
}