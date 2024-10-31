/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:13:51 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/30 22:13:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*env_list(t_shell *shell, char **envp)
{
	t_list	*env_list;
	void	*content;
	int		i;

	env_list = NULL;
	if (!envp || !*envp)
		return (printf("empty env\n"), NULL);
	i = 0;
	while (envp[i])
	{
		content = create_node_env(shell, &envp[i], i);
		if (!content)
			exit_failure(shell, "env_list");
		ft_lstadd_back(&env_list, ft_lstnew(content));
		i++;
	}
	return (env_list);
}

t_env	*create_node_env(t_shell *shell, char **envp, int index)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		exit_failure(shell, "create_node_env");
	node->key = index;
	node->value = env_value(shell, *envp);
	node->content = "example";
	return (node);
}

char	*env_value(t_shell *shell, char *env)
{
	char	*value;

	printf("env_len_1:%i\n", val_len(env));
	value = malloc(sizeof(char *) * (val_len(env) + 1));
	if (!value)
		exit_failure(shell, "env_value");
	ft_strlcpy(value, env, env_len(env, 1) + 1);
	return (value);
}

char	*env_content(t_shell *shell, char *env)
{
	int		i;
	int		j;
	char	*content;

	content = ft_calloc(sizeof(char), (env_len(env, 0) + 1));
	if (!content)
		exit_failure(shell, "env_value");
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	j = 0;
	while (env[i])
		content[j++] = env[i++];
	content[j] = '\0';
	return (content);
}

int	val_len(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	return (i);
}
