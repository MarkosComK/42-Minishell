/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ltree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:20:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 13:44:52 by marsoare         ###   ########.fr       */
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
		if (check_token(tmp) && ((t_token *)tmp->content)->type != PARENTHESIS)
		{
			while (check_token(tmp))
			{
				tmp = tmp->next;
			}
		}
		else
		{
			if (((t_token *)tmp->content)->type == PARENTHESIS)
			{
				tmp = tmp->next;
				while (((t_token *)tmp->content)->type != PARENTHESIS)
					tmp = tmp->next;
				tmp = tmp->next;
			}
			else
			{
				tmp = tmp->next;
				while (check_token(tmp) && ((t_token *)tmp->content)->type != PARENTHESIS)
				{
					tmp = tmp->next;
				}
			}
		}
	}
	return (lroot);
}

void	*insert_lnode(t_shell *shell, void *l_node, t_list *t_lst)
{
	t_token	*token;

	token = (t_token *)t_lst->content;
	//handle first token as parenthesis
	if (token->type == PARENTHESIS)
	{
		t_list	*new;

		new = NULL;
		new =  new_sublist(t_lst);
		print_token_lst(new);
		//build subtree based on ()
		if (!l_node)
			l_node = build_ltree(shell, new);
		if (token->type == AND_IF)
			l_node = create_and(shell, l_node, build_ltree(shell, new));
		//sublist not needed anymore
		clean_sublist(new);
		return (l_node);
	}
	if (!l_node)
		return (create_subtree(shell, t_lst));
	if (token->type == AND_IF && ((t_token *)t_lst->next->content)->type != PARENTHESIS)
		l_node = create_and(shell, l_node, create_subtree(shell, t_lst->next));
	else if (token->type == AND_IF && ((t_token *)t_lst->next->content)->type == PARENTHESIS)
	{
		t_list	*new;

		new = NULL;
		new =  new_sublist(t_lst);
		print_token_lst(new);
		//create subtree at right side of && when theres (new)
		l_node = create_and(shell, l_node, build_ltree(shell, new));
		//sublist not needed anymore
		clean_sublist(new);
	}
	else if (token->type == OR)
		l_node = create_or(shell, l_node, create_subtree(shell, t_lst->next));
	else
		return (NULL);
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

void	*create_and(t_shell *shell, void *left, void *right)
{
	t_andif	*node;

	node = malloc(sizeof(t_andif));
	if (!node)
		exit_failure(shell, "crete_andif");
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
		exit_failure(shell, "crete_or");
	node->type.type = N_OR;
	node->left = left;
	node->right = right;
	return (node);
}
