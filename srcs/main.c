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

void	update_shlvl(t_shell shell)
{
	t_list	*tmp;
	int		value;
	char	*n_value;

	tmp = shell.envp;
	while (tmp)
	{
		if (ft_strcmp(((t_env *)tmp->content)->value, "SHLVL=") == 0)
		{
			value = ft_atoi(((t_env *)tmp->content)->content);
			value++;
			n_value = ft_itoa(value);
			free(((t_env *)tmp->content)->content);
			((t_env *)tmp->content)->content = n_value;
		}
		tmp = tmp->next;
	}
	shell.envp = tmp;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;

	check_args(argc, argv, envp);
	env_list(&shell, envp);
	update_shlvl(shell);
	terminal(&shell, envp);
	free_env_lst(shell.envp);
	return (0);
}
