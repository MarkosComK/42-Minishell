/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:24:30 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/29 20:14:03 by hluiz-ma         ###   ########.fr       */
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
		env_arr[i] = ft_strjoin(((t_env *)envp_list->content)->value,
				((t_env *)envp_list->content)->content);
		if (!env_arr[i])
			exit_failure(shell, "env_arr_1");
		envp_list = envp_list->next;
		i++;
	}
	env_arr[i] = NULL;
	return (env_arr);
}

t_list	*path_list(t_shell *shell, char **envp)
{
	t_list	*path_list;
	char	*path;
	int		i;

	(void)envp;
	path_list = NULL;
	path = sh_get_env(shell->envp, "PATH");
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



void print_env_lst(t_list *lst)
{
    t_env *env_var;

    while (lst)
    {
        env_var = (t_env *)lst->content;
        if (env_var->content && ft_strchr(env_var->value, '='))
        {
            printf("%s", env_var->value);
            printf("%s\n", env_var->content);
        }
        lst = lst->next;
    }
}

void	free_env_lst(t_list *envp)
{
	t_list	*tmp;

	while (envp)
	{
		tmp = envp->next;
		free(((t_env *)envp->content)->value);
		free(((t_env *)envp->content)->content);
		free(envp->content);
		free(envp);
		envp = tmp;
	}
}