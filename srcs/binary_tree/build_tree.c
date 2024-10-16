/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 13:13:15 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_tree(t_list *token_list)
{
	t_list	*tmp;
	void	*root;
	t_node	*node;

	tmp = token_list;
	root = NULL;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		root = insert_node(root, tmp->content, tmp->next->content);
		node = (t_node *)root;
		if (node->type == N_PIPE)
			tmp = tmp->next;
		tmp = tmp->next;
	}
	return root;
}

void	*insert_node(void *node, t_token *curr_token, t_token *next_token)
{
	t_pipe	*pipe;

	if (!node)
		return (create_exec(curr_token));
	pipe = create_pipe(node, create_exec(next_token));
	return (pipe);
}

void	*create_exec(t_token *token)
{
	t_exec	*node;

	if (!token)
		return (NULL);
	node = (t_exec *)malloc(sizeof(t_exec));
	node->type.type = N_EXEC;
	node->command = token->value;
	return (node);
}

void	*create_pipe(t_exec *left, t_exec *right)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	node->type.type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}
