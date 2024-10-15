/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 20:40:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*create_exec(t_token *token)
{
	t_exec	*node;

	node = (t_exec *)malloc(sizeof(t_exec));
	node->type = N_EXEC;
	node->command = token->value;
	return (node);
}

void	*create_pipe(t_exec *left, t_exec *right)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	node->type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}

void	*insert_node(void *node, t_token *curr_token, t_token *next_token)
{
	t_pipe	*pipe;

	if (!node)
		return (create_exec(curr_token));
	pipe = create_pipe(node, create_exec(next_token));
	return (pipe);
}

void	*build_tree_from_tokens(t_list *token_list)
{
	t_token	*current_token = (t_token *)token_list->content;
	t_token	*next_token = (t_token *)token_list->next;
	void	*root = NULL;

	while (current_token)
	{
		root = insert_node(root, current_token, next_token);  // Build the BST from the tokens
		current_token = next_token;  // Move to the next token
		if (next_token)
			next_token = next_token->next; // Progress the next token
	}

	return root; // Return the root of the binary tree
}

