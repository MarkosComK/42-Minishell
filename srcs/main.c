/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:10:17 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/29 16:40:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Start checking for the proper run of the program before starts read the user input
 * using the terminal(); that runs readline();
 *
 * User should run:
 * $./minishell
 * with no extra args
*/

int main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;
	check_args(argc, argv, envp);
	terminal(&shell, envp);
	return 0;
}
