/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ltree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:20:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 10:37:39 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_token(t_list *node)
{
	return (node && (((t_token *)node->content)->type != AND_IF
			/*|| (t_token *)node->content)->type != OR */));
}

void	*build_ltree(t_shell *shell, t_list *token_list)
{
	t_list	*tmp;
	void	*lroot;

	tmp = token_list;
	lroot = NULL;
	while (tmp)
	{
		lroot = insert_lnode(shell, lroot, tmp);
		if (check_token(tmp))
		{
			while (check_token(tmp))
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tmp->next;
			while (check_token(tmp))
			{
				tmp = tmp->next;
			}
		}
	}
	return (lroot);
}

void	*insert_lnode(t_shell *shell, void *l_node, t_list *token_lst)
{
	t_token	*token;

	if (!l_node)
		return (create_subtree(shell, token_lst));
	token = (t_token *)token_lst->content;
	if (token->type == AND_IF)
		l_node = create_andif(shell, l_node, create_subtree(shell, token_lst->next));
	else if (token->type == OR)
		l_node = create_or(shell, l_node, create_subtree(shell, token_lst->next));
	else
		return NULL;
	return (l_node);
}

void	*create_subtree(t_shell *shell, t_list *token_lst)
{
	void	*subtree;

	if (!token_lst)
		return (NULL);
	subtree = build_tree(shell, token_lst);
	if (!subtree)
		exit_failure(shell, "create_subtree");
	return (subtree);
}

void	*create_andif(t_shell *shell, void *left, void *right)
{
	t_andif	*node;

	node = malloc(sizeof(t_andif));
	if (!node)
		exit_failure(shell, "crete_exec");
	node->type.type = N_ANDIF;
	node->left = left;
	node->right = right;
	return (node);
}

void	*create_or(t_shell *shell, void *left, void *right)
{
	t_or	*node;

	node = malloc(sizeof(t_or));
	if (!node)
		exit_failure(shell, "crete_exec");
	node->type.type = N_OR;
	node->left = left;
	node->right = right;
	return (node);
}
