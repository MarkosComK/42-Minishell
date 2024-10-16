/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_utls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:54:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 12:16:21 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void print_bst_pipe(t_pipe *node, int space)
{
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	if (node->type.type == N_PIPE)
	printf("[PIPE]\n");
}

void print_bst_exec(t_exec *node, int space)
{
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	printf("%s\n", node->command);
}

void print_pipe_children(t_pipe *pipe, int space)
{
	if (pipe->right)
		print_bst(pipe->right, space);
	print_bst_pipe(pipe, space);
	if (pipe->left)
		print_bst(pipe->left, space);
}

void *print_bst(void *root, int space)
{
	t_node *node;
	int		spacing;

	if (space == 5)
		printf("\n\n\nTREE VIEW:\n");
	spacing = 5;
	space += spacing;
	if (!root)
		return NULL;
	node = (t_node *)root;
	if (node->type == N_PIPE)
		print_pipe_children((t_pipe *)root, space);
	else
		print_bst_exec((t_exec *)root, space);
	return NULL;
}
