/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 04:19:00 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 16:31:28 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_infiles(t_shell *shell, t_exec *exec_node)
{
	int		fd;

	if (exec_node->infiles)
	{
		while (exec_node->infiles)
		{
			fd = open(exec_node->infiles->content, O_RDONLY);
			if (fd < 0)
			{
				infile_failure(shell, exec_node->infiles->content);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			exec_node->infiles = exec_node->infiles->next;
		}
	}
}

void	handle_outfiles(t_shell *shell, t_exec *exec_node)
{
	int		fd;
	t_outf	*outf;

	if (exec_node->outfiles)
	{
		while (exec_node->outfiles)
		{
			outf = ((t_outf *)exec_node->outfiles->content);
			if (outf->type == APP)
				fd = open(outf->name, O_RDWR | O_CREAT | O_APPEND , 0644);
			else if (outf->type == ADD)
				fd = open(outf->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				outfile_failure(shell, outf->name);
			}
			dup2(fd, STDOUT_FILENO);
			close(fd);
			exec_node->outfiles = exec_node->outfiles->next;
		}
	}
}
