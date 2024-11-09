/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ltree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:20:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 12:32:53 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_ltree(t_shell *shell, t_list *token_list)
{
	t_list	*tmp;
	void	*lroot;

	tmp = token_list;
	lroot = NULL;
	while (tmp)
	{
		lroot = insert_lnode(shell, lroot, tmp);
		if (((t_token *)tmp->content)->type != PIPE)
		{
			while (tmp && ((t_token *)tmp->content)->type != PIPE)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tmp->next;
			while (tmp && ((t_token *)tmp->content)->type != PIPE)
			{
				tmp = tmp->next;
			}
		}
	}
	return (lroot);
}

void	*insert_lnode(t_shell *shell, void *lnode, t_list *token_lst)
{
	void	*andif;

	if (!lnode)
		return (create_subtree(shell, token_lst));
	andif = create_andif(shell, lnode, create_subtree(shell, token_lst->next));
	return (andif);
}

void	*create_subtree(t_shell *shell, t_list *token_lst)
{
	void	*subtree;

	if (!token_lst)
		return (NULL);
	subtree = build_tree(shell, token_lst);
	if (!subtree)
		exit_failure(shell, "crete_exec");
	return (subtree);
}

void	*create_andif(t_shell *shell, t_exec *left, t_exec *right)
{
	t_andif	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	if (!node)
		exit_failure(shell, "crete_exec");
	node->type.type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}
