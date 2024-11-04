/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:10:17 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:28:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Start checking for the proper run of the program
 * before starts read the user input
 * using the terminal(); that runs readline();
 *
 * User should run:
 * $./minishell
 * with no extra args
 */

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;
	t_list	*tmp;

	for(int i = 0; envp[i]; i++)
	{
		printf("%s\n", envp[i]);
	}
	check_args(argc, argv, envp);
    env_list(&shell, envp);
	terminal(&shell, envp);
	while (shell.envp)
	{
		tmp = shell.envp->next;
		free(((t_env *)shell.envp->content)->value);
		free(((t_env *)shell.envp->content)->content);
		free(shell.envp->content);
		free(shell.envp);
		shell.envp = tmp;
	}
	return (0);
}
