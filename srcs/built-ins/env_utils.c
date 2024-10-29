/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:13:51 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/29 20:14:13 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		exit_failure(shell, "create_node_env");
	node->key = index;
	node->value = env_value(shell, *envp);
	node->content = env_content(shell, *envp);
	return (node);
}

char	*env_value(t_shell *shell, char *env)
{
	int		i;
	char	*value;

	value = ft_calloc(sizeof(char), (env_len(env, 1) + 1));
	if (!value)
		exit_failure(shell, "env_value");
	i = 0;
	while (env[i] && env[i] != '=')
	{
		value[i] = env[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

char	*env_content(t_shell *shell, char *env)
{
	int		i;
	char	*content;

	python3 - m c_formatter_42 int j;
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

int	env_len(char *env, int flag)
{
	int	i;
	int	size_content;

	i = 0;
	size_content = 0;
	if (flag == 1)
	{
		while (env[i] && env[i] != '=')
			i++;
		return (i);
	}
	else
	{
		while (env[i] && env[i] != '=')
			i++;
		while (env[i])
		{
			i++;
			size_content++;
		}
		return (size_content);
	}
}
