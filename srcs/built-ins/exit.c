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

int	is_numeric(const char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] && ft_isdigit(str[i]))
			flag = 1;
		else
			flag = 0;
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
	int	status;

	status = ft_atoi(args[1]);
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
