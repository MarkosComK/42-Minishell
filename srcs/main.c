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

void	free_env_lst(t_list *envp)
{
	t_list	*tmp;

	while (envp)
	{
		tmp = envp->next;
		free(((t_env *)envp->content)->value);
		free(((t_env *)envp->content)->content);
		free(envp->content);
		free(envp);
		envp = tmp;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;

	check_args(argc, argv, envp);
    env_list(&shell, envp);
	terminal(&shell, envp);
	free_env_lst(shell.envp);
	return (0);
}
