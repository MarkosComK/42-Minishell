/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:40 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 13:33:16 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unset(t_shell *shell, char **args)
{
	int	i;
	int exit_status;

	if (!args || !args[1])
		return ;
	exit_status = 0;
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			print_invalid_identifier(args[i], "unset");
			exit_status = 1;
		}
		else
			remove_env_var(shell, args[i]);
		i++;
	}
	exit_code(exit_status);
}

void	remove_first_node(t_shell *shell, t_list *curr)
{
	t_env	*env_var;

	env_var = (t_env *)curr->content;
	shell->envp = curr->next;
	free(env_var->value);
	free(env_var->content);
	free(env_var);
	free(curr);
}

void	remove_node(t_list *prev)
{
	t_list	*curr;
	t_env	*env_var;

	if (!prev || !prev->next)
		return ;
	curr = prev->next;
	env_var = (t_env *)curr->content;
	prev->next = curr->next;
	free(env_var->value);
	free(env_var->content);
	free(env_var);
	free(curr);
}

int	check_first_node(t_shell *shell, const char *var_name)
{
	t_list	*curr;
	t_env	*env_var;
	size_t	var_len;

	if (!shell->envp)
		return (0);
	curr = shell->envp;
	env_var = (t_env *)curr->content;
	var_len = ft_strlen(var_name);
	if (ft_strncmp(env_var->value, var_name, var_len) == 0
		&& env_var->value[var_len] == '=')
	{
		remove_first_node(shell, curr);
		return (1);
	}
	return (0);
}

t_list	*find_prev_node(t_list *lst, const char *var_name)
{
	t_list	*curr;
	t_env	*env_var;
	size_t	var_len;

	if (!lst || !lst->next)
		return (NULL);
	var_len = ft_strlen(var_name);
	curr = lst;
	while (curr->next)
	{
		env_var = (t_env *)curr->next->content;
		if (ft_strncmp(env_var->value, var_name, var_len) == 0
			&& env_var->value[var_len] == '=')
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
