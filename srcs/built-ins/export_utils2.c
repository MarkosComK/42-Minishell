/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:36 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:43 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	update_existing_var(t_env *env_var, t_env *new_env)
{
	char	*tmp_content;
	char	*plus;

	plus = ft_strnstr(new_env->value, "+=", ft_strlen(new_env->value));
	if (plus)
	{
		tmp_content = ft_strjoin(env_var->content, new_env->content);
		free(env_var->content);
		env_var->content = tmp_content;
		free(new_env->value);
		free(new_env->content);
	}
	else
	{
		free(env_var->value);
		free(env_var->content);
		env_var->value = new_env->value;
		env_var->content = new_env->content;
	}
	env_var->is_export = true;
	env_var->printed = false;
	free(new_env);
}

void	upt_env_var(t_shell *shell, t_env *new_env)
{
	t_list	*env_list;
	t_env	*env_var;

	env_list = shell->envp;
	while (env_list)
	{
		env_var = env_list->content;
		if (is_exact_var(env_var, new_env->value))
		{
			update_existing_var(env_var, new_env);
			return ;
		}
		env_list = env_list->next;
	}
	ft_lstadd_back(&shell->envp, ft_lstnew(new_env));
}
