/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:36 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 13:43:22 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_export(t_shell *shell, char **args)
{
	int	i;
	int status;
	int ret;

	status = 0;
	if (!args[1])
	{
		print_export_lst(shell->envp);
		exit_code (0);
		return ;
	}
	i = 1;
	while (args[i])
	{
		ret = export_var(shell, args[i]);
		if(ret != 0)
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

int	export_var(t_shell *shell, const char *arg)
{
	t_env	*new_env;
	char	*equal;

	if (!is_valid_identifier(arg))
	{
		print_invalid_identifier((char *)arg, "export");
		return (1);
	}
	equal = ft_strchr(arg, '=');
	if (!equal && !ft_strchr(arg, '='))
	{
		mark_isexport(shell, arg);
		return (0);
	}
	new_env = malloc(sizeof(t_env));
	if (!new_env)
		exit_failure(shell, "export_var");
	new_env->value = create_value(shell, arg, equal);
	new_env->content = ft_strdup(equal + 1);
	new_env->is_export = true;
	new_env->printed = false;
	upt_env_var(shell, new_env);
	return (0);
}

void	update_existing_var(t_env *env_var, t_env *new_env)
{
	free(env_var->value);
	free(env_var->content);
	env_var->value = new_env->value;
	env_var->content = new_env->content;
	env_var->is_export = true;
	env_var->printed = false;
	free(new_env);
}

void	upt_env_var(t_shell *shell, t_env *new_env)
{
	t_list	*env_list;
	t_env	*env_var;
	int		len;

	env_list = shell->envp;
	len = ft_strlen(new_env->value) - 1;
	while (env_list)
	{
		env_var = env_list->content;
		if (ft_strncmp(env_var->value, new_env->value, len) == 0
			&& (env_var->value[len] == '=' || env_var->value[len] == '\0'))
		{
			update_existing_var(env_var, new_env);
			return ;
		}
		env_list = env_list->next;
	}
	ft_lstadd_back(&shell->envp, ft_lstnew(new_env));
}
