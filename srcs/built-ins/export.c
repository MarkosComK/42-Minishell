/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:36 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:33 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(t_shell *shell, char **args)
{
	int	i;
	int	status;
	int	ret;

	status = 0;
	if (!args[1])
	{
		print_export_lst(shell->envp);
		exit_code(0);
		return ;
	}
	i = 1;
	while (args[i])
	{
		ret = export_var(shell, args[i]);
		if (ret != 0)
			status = ret;
		i++;
	}
	exit_code(status);
}

char	*create_value(t_shell *shell, const char *arg, char *equal)
{
	char	*value;
	int		len;

	if (equal)
		len = equal - arg;
	else
		len = ft_strlen(arg);
	value = malloc(len + 2);
	if (!value)
		exit_failure(shell, "create_value");
	ft_strlcpy(value, arg, len + 1);
	value[len] = '=';
	value[len + 1] = '\0';
	return (value);
}

void	handle_append(t_shell *shell, t_env *new_env, const char *arg,
		char *plus)
{
	t_list	*current;
	t_env	*env_var;
	char	*var_name;

	var_name = ft_substr(arg, 0, plus - arg);
	if (!var_name)
		exit_failure(shell, "handle_append");
	current = shell->envp;
	while (current)
	{
		env_var = current->content;
		if (is_exact_var(env_var, var_name))
		{
			new_env->content = ft_strjoin(env_var->content, plus + 2);
			break ;
		}
		current = current->next;
	}
	if (!current)
		new_env->content = ft_strdup(plus + 2);
	new_env->value = ft_strjoin(var_name, "=");
	if (!new_env->content || !new_env->value)
		exit_failure(shell, "handle_append");
	free(var_name);
}

int	handle_export_var(t_shell *shell, const char *arg, char *equal, char *plus)
{
	t_env	*new_env;

	if (!equal && !ft_strchr(arg, '='))
	{
		mark_isexport(shell, arg);
		return (0);
	}
	new_env = malloc(sizeof(t_env));
	if (!new_env)
		exit_failure(shell, "export_var");
	if (plus && plus[1] == '=')
		handle_append(shell, new_env, arg, plus);
	else
	{
		new_env->value = create_value(shell, arg, equal);
		new_env->content = ft_strdup(equal + 1);
	}
	new_env->is_export = true;
	new_env->printed = false;
	upt_env_var(shell, new_env);
	return (0);
}

int	export_var(t_shell *shell, const char *arg)
{
	char	*equal;
	char	*plus;

	if (arg[0] == '_' && arg[1] == '=')
		return (0);
	if (!is_valid_identifier(arg))
	{
		print_invalid_identifier((char *)arg, "export");
		return (1);
	}
	equal = ft_strchr(arg, '=');
	plus = ft_strchr(arg, '+');
	return (handle_export_var(shell, arg, equal, plus));
}
