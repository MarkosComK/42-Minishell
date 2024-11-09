/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:34 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/29 21:27:10 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	exit_error(t_shell *shell, char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
	free_shell(shell);
	exit_code(255);
}

void	numeric_exit(t_shell *shell, char **args)
{
	int	status;

	status = ft_atoi(args[1]);
	if (args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		exit_code(1);
		return ;
	}
	free_shell(shell);
	exit((unsigned char)status);
}

void	ft_exit(t_shell *shell, t_exec *exec_node)
{
	long	status;
	char	**args;

	args = exec_node->argv;
	ft_putstr_fd("exit\n", 1);
	if (!args[1])
	{
		status = exit_code(-1);
		free_shell(shell);
		exit(status);
	}
	if (!is_numeric(args[1]))
	{
		exit_error(shell, args[1]);
		return ;
	}
	numeric_exit(shell, args);
}
