/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:13:51 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/01 16:33:13 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*env_list(t_shell *shell, char **envp)
{
	t_list	*env_list;
	t_env	*content;
	int		i;

	env_list = NULL;
	if (!envp || !*envp)
		return (printf("empty env\n"), NULL);
	i = 0;
	while (envp[i])
	{
		content = create_node_env(shell, &envp[i]);
		if (!content)
			exit_failure(shell, "env_list");
		ft_lstadd_back(&env_list, ft_lstnew(content));
		i++;
	}
	return (env_list);
}

t_env	*create_node_env(t_shell *shell, char **envp)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		exit_failure(shell, "create_node_env");
	node->value = get_value(shell, *envp);
	node->content = get_content(shell, *envp);
	return (node);
}

char	*get_value(t_shell *shell, char *env)
{
	char	*value;

	value = malloc(sizeof(char) * (val_size(env) + 1));
	if (!value)
		exit_failure(shell, "env_value");
	ft_strlcpy(value, env, val_size(env) + 1);
	return (value);
}

char	*get_content(t_shell *shell, char *env)
{
	char	*value;

	value = malloc(sizeof(char) * (content_size(env) + 1));
	if (!value)
		exit_failure(shell, "env_value");
	ft_strlcpy(value, env + val_size(env), ft_strlen(env));
	return (value);
}
