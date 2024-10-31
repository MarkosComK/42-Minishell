/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:41 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 04:38:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_bst(void *root)
{
	t_node	*node;

	if (!root)
		return ;
	node = (t_node *)root;
	if (node->type == N_PIPE)
		free_pipe_children((t_pipe *)root);
	else
		free_exec((t_exec *)root);
	return ;
}

void	free_pipe_children(t_pipe *pipe)
{
	if (pipe)
	{
		if (pipe->left)
			free_bst(pipe->left);
		if (pipe->right)
			free_bst(pipe->right);
	}
	free(pipe);
}

void	free_outf(void *content)
{
	const t_outf *outfile = (t_outf *)content;

	if (outfile)
	{
		free(outfile->name);
		free((void *)outfile);
	}
}

void	free_exec(t_exec *node)
{
	if (node)
	{
		if (node->argv)
			free(node->argv);
		if (node->infiles)
		{
			ft_lstclear(&node->infiles, free);
			/*
			while (node->infiles)
			{
				tmp = node->infiles->next;
				free(node->infiles->content);
				free(node->infiles);
				node->infiles = tmp;
			}
			*/
		}
		free(node->infiles);
		if (node->outfiles)
		{
			/*
			while (node->outfiles)
			{
				t_list *tmp = node->outfiles->next;
				free(((t_outf *)node->outfiles->content)->name);
				free(node->outfiles->content);
				free(node->outfiles);
				node->outfiles = tmp;
			}
			*/
			ft_lstclear(&node->outfiles, free_outf);
		}
		free(node->outfiles);
		free(node);
	}
}
