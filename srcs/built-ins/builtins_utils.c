/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/28 21:29:48 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(const char *command)
{
	const char	*builtins[8];
	int			i;

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	while (builtins[i])
	{
		if (ft_strcmp((char *)command, (char *)builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	exec_builtin(t_shell *shell, t_exec *exec_node)
{
	if (ft_strcmp(exec_node->argv[0], "echo") == 0)
		return (ft_echo(exec_node));
	if (ft_strcmp(exec_node->argv[0], "pwd") == 0)
		return (check_pwd(exec_node));
	if (ft_strcmp(exec_node->argv[0], "env") == 0)
		return (print_env_lst(shell->envp), 0);
	return (1);
}

void	ft_putendl_fd_pt(char *s, int fd)
{
	if (!s)
	{
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
