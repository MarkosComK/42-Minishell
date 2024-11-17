/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:49:49 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:27:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_args(int argc, char *argv[], char *envp[])
{
	(void) argv;
	if (!envp || !*envp)
	{
		ft_putendl_fd(RED""DEFAULT, 2);
	}
	if (argc > 1)
	{
		ft_putendl_fd(RED"Invalid input"DEFAULT, 2);
		exit(1);
	}
	return (0);
}
