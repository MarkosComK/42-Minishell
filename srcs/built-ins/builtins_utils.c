/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/03 20:26:42 by hluiz-ma         ###   ########.fr       */
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
/*
int	exec_builtin(t_shell *shell, t_exec *exec_node)
{
	if (ft_strcmp(exec_node->argv[0], "echo") == 0)
		return (ft_echo(exec_node));
	if (ft_strcmp(exec_node->argv[0], "pwd") == 0)
		return (ft_pwd(), 0);
	if (ft_strcmp(exec_node->argv[0], "env") == 0)
		return (print_env_lst(shell->envp), 0);
	if (ft_strcmp(exec_node->argv[0], "export") == 0)
		return (ft_export(shell, exec_node->argv), 0);	
	return (1);
}

int is_env_builtin(const char *command)
{
    return (ft_strcmp(command, "export") == 0 || 
            ft_strcmp(command, "unset") == 0 || 
            ft_strcmp(command, "cd") == 0);
}

int	is_parent_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	return (0);
}

void	exec_parent_builtin(t_shell *shell)
{
	char	*cmd;

	cmd = shell->root->cmd;
	if (!ft_strcmp(cmd, "cd"))
		builtin_cd(shell);
	 if (!ft_strcmp(cmd, "export"))
		builtin_export(shell);
	else if (!ft_strcmp(cmd, "unset"))
		builtin_unset(shell);
	else if (!ft_strcmp(cmd, "env"))
		builtin_env(shell);
}*/

int	is_parent_builtin(t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (!cmd)
		return (0);
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
	if (!ft_strcmp(cmd, "export"))
		return ((ft_export(shell, exec_node->argv)), 0);
	return (1);
}

int	exec_builtin(t_shell *shell, t_exec *exec_node)
{
	char	*cmd;

	cmd = exec_node->argv[0];
	if (!cmd)
		return (1);
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
