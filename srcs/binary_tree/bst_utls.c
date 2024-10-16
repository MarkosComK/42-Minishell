/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_utls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:54:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 11:24:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void print_bst_pipe(t_pipe *node, int space)
{
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	printf("[%c]\n", node->type.type);
}

void print_bst_exec(t_exec *node, int space)
{
	printf("\n");
	for (int i = 5; i < space; i++)
		printf(" ");
	printf("%s\n", node->command);
}

void	*print_bst(void *root, int space)
{
	int		spacing;
	t_node	*node;
	//t_pipe		*pipe;
	//t_exec		*exec;

	spacing = 5;
	space += spacing;
	if (!root)
		return NULL;
	node = (t_node *)root;
	if (node->type == N_PIPE && ((t_pipe *)root)->right)
		print_bst((t_exec *)((t_pipe *)root)->right, space);
	if (node->type == N_PIPE && ((t_pipe *)root)->right && ((t_pipe *)root)->left)
		print_bst_pipe((t_pipe *)root, space);
	if (node->type == N_PIPE && ((t_pipe *)root)->left)
		print_bst((t_exec *)((t_pipe *)root)->left, space);
	if (node->type != N_PIPE)
		print_bst_exec((t_exec *)root, space);
	return NULL;
}
