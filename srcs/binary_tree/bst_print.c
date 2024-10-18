/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:54:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 12:33:00 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*print_bst(void *root, int space)
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
	if (node->type == N_PIPE)
		print_pipe_children((t_pipe *)root, space);
	else
		print_bst_exec((t_exec *)root, space);
	return (NULL);
}

void	print_pipe_children(t_pipe *pipe, int space)
{
	if (pipe->right)
		print_bst(pipe->right, space);
	print_bst_pipe(pipe, space);
	if (pipe->left)
		print_bst(pipe->left, space);
}

void	print_bst_pipe(t_pipe *node, int space)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (node->type.type == N_PIPE)
		printf("[PIPE]\n");
}

void	print_bst_exec(t_exec *node, int space)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n");
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("[EXEC]\n");
	if (node->argv)
	{
		while (node->argv[j])
		{
			i = 0;
			while (i < space + 2)
			{
				printf(" ");
				i++;
			}
			printf("[%s]\n", node->argv[j]);
			j++;
		}
	}
}
