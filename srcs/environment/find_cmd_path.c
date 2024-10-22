/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:18:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 22:57:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_cmd_path(t_list *path_list, char *command)
{
	char	*cmd_path;
	char	*only_path;
	t_list	*current;
	char	*path_dir;

	current = path_list;
	while (current != NULL)
	{
		path_dir = (char *)current->content;
		only_path = ft_strjoin(path_dir, "/");
		if (!only_path)
		{
			perror("ft_strjoin");
			return (NULL);
		}
		cmd_path = ft_strjoin(only_path, command);
		free(only_path);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		current = current->next;
	}
	return (NULL);
}
