/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 04:19:00 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 04:28:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_infiles(t_shell *shell, t_exec *exec_node)
{
	int		i;
	int		fd;

	i = 0;
	if (exec_node->infiles)
	{
		while (exec_node->infiles[i])
		{
			fd = open(exec_node->infiles[i], O_RDONLY);
			if (fd < 0)
			{
				exit_failure(shell, "INFILE FAILURE\n");
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			i++;
		}
	}
}

void	handle_outfiles(t_shell *shell, t_exec *exec_node)
{
	int		i;
	int		fd;

	i = 0;
	if (exec_node->outfiles)
	{
		while (exec_node->outfiles[i])
		{
			fd = open(exec_node->outfiles[i], O_RDWR | O_CREAT, 0644);
			if (fd < 0)
			{
				exit_failure(shell, "INFILE FAILURE\n");
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			i++;
		}
	}
}
