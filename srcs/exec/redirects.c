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

void	check_files_order(t_shell *shell, t_exec *exec_node)
{
	t_list	*t_list;
	t_token	*token;
	int		in;
	int		out;

	t_list = shell->token_lst;
	in = 0;
	out = 0;
	while (t_list)
	{
		token = ((t_token *)t_list->content);
		if (token->type == INFILE)
		{
			handle_infiles(shell, exec_node->infiles, in);
			in++;
		}
		else if (token->type == OUTFILE || token->type == APPEND)
		{
			handle_outfiles(shell, exec_node->outfiles, out);
			out++;
		}
		t_list = t_list->next;
	}
	handle_infiles(shell, exec_node->infiles, -1);
	handle_outfiles(shell, exec_node->outfiles, -1);
}

void	handle_infiles(t_shell *shell, t_list *infiles, int pos)
{
	int		fd;
	t_inf	*inf;
	int		index;

	index = 0;
	if (infiles)
	{
		while (infiles)
		{
			if (index == pos || pos == -1)
			{
				inf = ((t_inf *)infiles->content);
				if (inf->type == INF)
					fd = open(inf->eof, O_RDONLY);
				else if (inf->type == HERE)
					fd = open(inf->name, O_RDWR, 0644);
				if (fd < 0)
					infile_failure(shell, inf->eof);
				dup2(fd, STDIN_FILENO);
				close(fd);
			}
			infiles = infiles->next;
			index++;
		}
	}
}

void	handle_outfiles(t_shell *shell, t_list *outfiles, int pos)
{
	int		fd;
	t_outf	*outf;
	int		index;

	index = 0;
	if (outfiles)
	{
		while (outfiles)
		{
			if (index == pos || pos == -1)
			{
				outf = ((t_outf *)outfiles->content);
				if (outf->type == APP)
					fd = open(outf->name, O_RDWR | O_CREAT | O_APPEND, 0644);
				else if (outf->type == ADD)
					fd = open(outf->name, O_RDWR | O_CREAT | O_TRUNC, 0644);
				if (fd < 0)
					outfile_failure(shell, outf->name);
				dup2(fd, STDOUT_FILENO);
				close(fd);
			}
			outfiles = outfiles->next;
			index++;
		}
	}
}
