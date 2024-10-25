/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:18:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 16:42:00 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*find_cmd_path(t_shell *shell, t_list *path_list, char *command)
{
	char	*path;
	char	*only_path;
	t_list	*current;
	char	*path_dir;

	current = path_list;
	if (!ft_strcmp(command, ""))
		return (ft_strdup(""));
	if (!command || ft_strlen(command) == 0)
		return (NULL);
	while (current != NULL)
	{
		path_dir = (char *)current->content;
		only_path = ft_strjoin(path_dir, "/");
		path = ft_strjoin(only_path, command);
		free(only_path);
		if (!path)
			exit_failure(shell, "find_cmd_path");
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		current = current->next;
	}
	return (ft_strdup(command));
}
