/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:08:09 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 17:22:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
void	*ltree_print(void *root, int space)
{
	t_node	*node;
	int		spacing;

	if (space == 5)
		printf("\n\n\nLOGICAL TREE VIEW:\n");
	spacing = 5;
	space += spacing;
	if (!root)
		return (NULL);
	node = (t_node *)root;
	if (node->type == N_ANDIF)
	{
		ltree_print(((t_andif *)root)->right, space);
		printf("%*s", space, "");
		printf("-> [&&]\n");
		ltree_print(((t_andif *)root)->left, space);
	}
	else if (node->type == N_PIPE)
		print_bst((t_pipe *)root, space + spacing);
	else if (node->type == N_EXEC)
		print_bst_exec((t_exec *)root, space + spacing);
	return (NULL);
}

void	ltree_free(void *root)
{
	t_node	*node;

	if (!root)
		return ;
	node = (t_node *)root;
	if (node->type == N_ANDIF)
	{
		ltree_free(((t_andif *)root)->right);
		ltree_free(((t_andif *)root)->left);
	}
	if (node->type != N_ANDIF)
		free_bst((t_pipe *)root);
	else
		free(root);
	return ;
}
