/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:34 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 14:16:20 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_limits(char *str, long long num)
{
	if (num > LLONG_MAX || num < LLONG_MIN)
		return (0);
	if (num == LLONG_MAX && ft_strcmp(str, "9223372036854775807"))
	{
		return (0);
	}
	if (num == LLONG_MIN && ft_strcmp(str, "-9223372036854775808"))
	{
		return (0);
	}
	return (1);
}

int	is_numeric(char *str)
{
	int			i;
	int			flag;
	long long	num;

	i = 0;
	flag = 0;
	num = ft_atoll(str);
	if (!check_limits(str, num))
		return (0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
			flag = 1;
		else
			return (0);
		i++;
	}
	return (flag);
}

void	exit_error(t_shell *shell, char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
	free_env_lst(shell->envp);
	free_shell(shell);
	exit_code(2);
	exit(2);
}

void	numeric_exit(t_shell *shell, char **args)
{
	long long	status;

	status = ft_atoll(args[1]);
	if (args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		exit_code(1);
		return ;
	}
	free_env_lst(shell->envp);
	free_shell(shell);
	exit((unsigned char)status);
}

void	ft_exit(t_shell *shell, t_exec *exec_node)
{
	char	**args;

	args = exec_node->argv;
	ft_putstr_fd("exit\n", 1);
	if (is_numeric(args[1]))
		numeric_exit(shell, args);
	if (!is_numeric(args[1]))
	{
		exit_error(shell, args[1]);
		return ;
	}
	return ;
}
