/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:41 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 17:12:29 by marsoare         ###   ########.fr       */
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

void	free_inf(void *content)
{
	const t_inf	*infile = (t_inf *)content;

	if (infile)
	{
		free(infile->name);
		free(infile->eof);
		free((void *)infile);
	}
}

void	free_outf(void *content)
{
	const t_outf	*outfile = (t_outf *)content;

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
			ft_lstclear(&node->infiles, free_inf);
		}
		free(node->infiles);
		if (node->outfiles)
		{
			ft_lstclear(&node->outfiles, free_outf);
		}
		free(node->outfiles);
		free(node);
	}
}
