/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 14:12:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_builtin(const char *command)
{
	const char	*builtins[7] = {"echo", "cd", "pwd",
		"export", "unset", "env", "exit"};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp((char *)command, (char *)builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_parent_builtin(t_exec *exec_node)
{
	char	*cmd;

	cmd = NULL;
	if (exec_node->argv)
		cmd = exec_node->argv[0];
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}

int	exec_parent_builtin(t_shell *shell, t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (!cmd)
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (ft_exit(shell, exec_node), 0);
	if (!ft_strcmp(cmd, "export"))
	{
		ft_export(shell, exec_node->argv);
		return (exit_code(-1));
	}
	if (!ft_strcmp(cmd, "unset"))
		return ((ft_unset(shell, exec_node->argv)), 0);
	if (!ft_strcmp(cmd, "cd"))
		return ((ft_cd(shell, exec_node)));
	return (1);
}

int	exec_builtin(t_shell *shell, t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (!cmd)
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (ft_exit(shell, exec_node), 0);
	if (!ft_strcmp(cmd, "echo"))
		return (ft_echo(exec_node));
	if (!ft_strcmp(cmd, "pwd"))
		return (ft_pwd(), 0);
	if (!ft_strcmp(cmd, "env"))
		return (print_env_lst(shell->envp), 0);
	return (1);
}

int	handle_builtins(t_shell *shell, t_exec *exec_node)
{
	if (!exec_node || !exec_node->argv[0])
		return (1);
	if (is_parent_builtin(exec_node))
	{
		return (exec_parent_builtin(shell, exec_node));
	}
	return (exec_builtin(shell, exec_node));
}
