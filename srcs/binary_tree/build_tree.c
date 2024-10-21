/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/18 16:29:11 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_tree(t_list *token_list)
{
	t_list	*tmp;
	void	*root;

	tmp = token_list;
	root = NULL;
	while (tmp)
	{
		root = insert_node(root, tmp);
		if (((t_token *)tmp->content)->type == WORD)
		{
			while (tmp && ((t_token *)tmp->content)->type == WORD)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tmp->next;
			while (tmp && ((t_token *)tmp->content)->type == WORD)
			{
				tmp = tmp->next;
			}
		}
	}
	return (root);
}

void	*insert_node(void *node, t_list *token_lst)
{
	t_pipe	*pipe;

	if (!node)
		return (create_exec(token_lst));
	pipe = create_pipe(node, create_exec(token_lst->next));
	return (pipe);
}

void	*create_exec(t_list *token_lst)
{
	t_exec	*node;

	if (!token_lst)
		return (NULL);
	node = (t_exec *)malloc(sizeof(t_exec));
	node->type.type = N_EXEC;
	node->command = ((t_token *)token_lst->content)->value;
	node->argv = get_argv(token_lst);
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
