/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:36 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/01 18:54:39 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_export(t_shell *shell, char **args)
{
    int i;
    
    if(!args[1])
    {
        print_env_lst(shell->envp);
    }
    i = 1;
    while(args[i])
    {
        export_var(shell, args[i]);
        i++;
    }
}

char	*create_value(t_shell *shell, const char *arg, char *equal)
{
	char	*value;
	int		len;

	printf("\n[DEBUG] create_value - arg: '%s'\n", arg);
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

void	export_var(t_shell *shell, const char *arg)
{
	char	*value;
	char	*content;
	char	*equal;

	if (!arg || !shell)
		return ;
	equal = ft_strchr(arg, '=');
	value = create_value(shell, arg, equal);
	if (equal)
		content = ft_strdup(equal + 1);
	else
		content = ft_strdup("");
	upt_env_var(shell, value, content);
}

void upt_env_var(t_shell *shell, char *value, char *content)
{
    t_list *env_list;
    t_env *env_var;
    t_env *new_env;
    
    env_list = shell->envp;
    while(env_list)
    {
        env_var = (t_env *)env_list->content;
        if(ft_strcmp(env_var->value, value) == 0)
        {
			free(env_var->content);
			env_var->content = content;
			free(value);
			return ;
        }
        env_list = env_list->next;        
    }
	new_env = malloc(sizeof(t_env));
	if (!new_env)
		exit_failure(shell, "upt_env_var");
	new_env->value = value;
	new_env->content = content;
	ft_lstadd_back(&shell->envp, ft_lstnew(new_env));
}   

