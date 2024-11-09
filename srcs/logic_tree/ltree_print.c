/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:08:09 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 15:15:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*ltree_print(void *root, int space)
{
	t_node	*node;
	int		spacing;

	if (space == 5)
		printf("\n\n\nTREE VIEW:\n");
	spacing = 5;
	space += spacing;
	if (!root)
		return (NULL);
	node = (t_node *)root;
	if (node->type == N_ANDIF)
		ltree_print(((t_andif *)root)->right, space);
	if (node->type == N_ANDIF)
		ltree_print(((t_andif *)root)->left, space);
	else if (node->type == N_PIPE)
		print_bst((t_pipe *)root, space);
	else if (node->type == N_EXEC)
		print_bst_exec((t_exec *)root, space);
	return (NULL);
}
