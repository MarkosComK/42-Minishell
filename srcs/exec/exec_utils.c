/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:01:00 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/16 13:51:29 by marsoare         ###   ########.fr       */
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
	if (ft_strcmp(command, ".") == 0 || ft_strcmp(command, "..") == 0)
		return (ft_strdup(command));
	if (!command || ft_strlen(command) == 0 || !ft_strcmp(command, ""))
		return (ft_strdup(""));
	while (current != NULL)
	{
		path_dir = (char *)current->content;
		only_path = ft_strjoin(path_dir, "/");
		path = ft_strjoin(only_path, command);
		free(only_path);
		if (!path)
			exit_failure(shell, "find_cmd_path");
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		current = current->next;
	}
	return (ft_strdup(command));
}

void	exec_free(t_shell *shell, t_exec *exec_node)
{
	free_expand(exec_node->argv);
	free_env_lst(shell->envp);
	free_shell(shell);
}
