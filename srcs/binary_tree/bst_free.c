/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:37:41 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 13:00:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_bst(void *root);

void free_pipe_children(t_pipe *pipe)
{
	if (pipe)
	{
		if (pipe->right)
			free_bst(pipe->right);
		if (pipe->left)
			free_bst(pipe->left);
	}
}

void free_exec(t_exec *node)
{
	if (node)
		free(node);
}

void	free_bst(void *root)
{
	t_node *node;

	if (!root)
		return ;
	node = (t_node *)root;
	if (node->type == N_PIPE)
		free_pipe_children((t_pipe *)root);
	else
		free_exec((t_exec *)root);
	return ;
}
