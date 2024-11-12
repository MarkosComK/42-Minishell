/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltree_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:43:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 13:44:00 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*new_sublist(t_list *t_lst)
{
	t_token	*token;

	token = (t_token *)t_lst->content;
	t_list	*new = NULL;
	t_lst = t_lst->next;
	token = (t_token *)t_lst->content;
	while (t_lst && token->type != PARENTHESIS)
	{
		ft_lstadd_back(&new, ft_lstnew(token));
		t_lst = t_lst->next;
		token = (t_token *)t_lst->content;
	}
	return (new);
}

void	clean_sublist(t_list *new)
{
	t_list *tmp;

	tmp = new;
	while (new)
	{
		tmp = new->next;
		free(new);
		new = tmp;
	}
}

void	*get_andif_subnode(t_shell *shell, void *l_node, t_list *t_lst)
{
	t_list	*new;

	new = NULL;
	new = new_sublist(t_lst->next);
	l_node = create_and(shell, l_node, build_ltree(shell, new));
	clean_sublist(new);
	return (l_node);
}

void	*get_or_subnode(t_shell *shell, void *l_node, t_list *t_lst)
{
	t_list	*new;

	new = NULL;
	new = new_sublist(t_lst->next);
	l_node = create_or(shell, l_node, build_ltree(shell, new));
	clean_sublist(new);
	return (l_node);
}
