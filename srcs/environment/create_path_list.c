/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:39:45 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 15:21:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_path(t_list	**path_list, char *path, int i);

t_list	*path_list(char **envp)
{
	t_list	*path_list;
	char	*path;
	int		i;
	(void)	envp;

	path_list = NULL;
	path = getenv("PATH");
	i = 0;
	while (path[i])
	{
		i = get_path(&path_list, path, i);
	}
	return (path_list);
}

int	get_path(t_list	**path_list, char *path, int i)
{
	char	*new_path;
	int		start;

	start = i;
	while (path[i] && path[i] != ':')
		i++;
	new_path = ft_substr(path, start, i - start);
	ft_lstadd_back(path_list, ft_lstnew(new_path));
	if (path[i] == ':') //handles the last path of the path list
		i++;
	return (i);
}
