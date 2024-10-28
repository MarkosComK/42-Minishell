/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:20 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_echo(t_exec *exec_node)
{
	bool			newline;
	unsigned int	i;

	newline = true;
	i = 1;
	if (exec_node->argv[i] && echo_flag_n(exec_node->argv[i]))
	{
		newline = false;
		i++;
	}
	echo_output(exec_node->argv, i, newline);
	return (0);
}

int	echo_flag_n(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_output(char **args, int idx, int newline)
{
	unsigned int	i;

	i = idx;
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
}
