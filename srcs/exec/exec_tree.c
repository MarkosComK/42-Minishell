/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:37:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

void	exec_tree(t_shell *shell, void *root)
{
	char	*cmd_path = find_cmd_path(shell->path, ((t_exec *)root)->command);
	printf("cmd_path: %s\n", cmd_path);
	if (execve(cmd_path, ((t_exec *)root)->argv, NULL) == -1)
	{
		free_shell(shell);
		exit(1);
	}
}
