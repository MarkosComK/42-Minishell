/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:24:30 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/29 18:41:36 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**env_arr(t_shell *shell)
{
	t_list	*envp_list;
	char	**env_arr;
	int		i;

	envp_list = shell->envp;
	i = ft_lstsize(envp_list);
	env_arr = malloc(sizeof(char *) * (i + 1));
	if (!env_arr)
		exit_failure(shell, "env_arr");
	i = 0;
	while (envp_list)
	{
		env_arr[i] = ft_strdup(envp_list->content);
		if (!env_arr[i])
			exit_failure(shell, "env_arr_1");
		envp_list = envp_list->next;
		i++;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
t_list	*env_list(t_shell *shell, char **envp)
{
	t_list	*env_list;
	char	*content;
	int i;

	env_list = NULL;
	if (!envp || !*envp)
		return (printf("empty env\n"), NULL);
	i = 0;
	while (envp[i])
	{
		content = ft_strdup(*envp);//create_node_env(shell, i);
		if (!content)
			exit_failure(shell, "env_list");
		ft_lstadd_back(&env_list, ft_lstnew(content));
		i++;
	}
	return (env_list);
}
/*
t_list	*create_node_env(t_shell *shell, int index)
{
	t_env	*node;

	node = ft_calloc(1, sizeof(t_env));
	if (!node)
		exit_failure(shell, "create_node_env");
	
	t_env->key= i;
	t_env->value = 
	t_env->content =

	return(node);
}
*/

t_list	*path_list(t_shell *shell, char **envp)
{
	t_list	*path_list;
	char	*path;
	int		i;

	(void)envp;
	path_list = NULL;
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	i = 0;
	while (path[i])
	{
		i = get_path(shell, &path_list, path, i);
	}
	return (path_list);
}

int	get_path(t_shell *shell, t_list **path_list, char *path, int i)
{
	char	*new_path;
	int		start;

	start = i;
	while (path[i] && path[i] != ':')
		i++;
	new_path = ft_substr(path, start, i - start);
	if (!new_path)
		exit_failure(shell, "get_path");
	ft_lstadd_back(path_list, ft_lstnew(new_path));
	if (path[i] == ':')
		i++;
	return (i);
}

void	print_env_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
