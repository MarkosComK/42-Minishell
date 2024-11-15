/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltree_parenthesis2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:51:53 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 17:07:49 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*start_parenthesis(t_shell *shell, t_list *t_lst, void *l_node)
{
	t_list	*new;
	t_token	*token;

	new = NULL;
	new = new_sublist(t_lst);
	token = (t_token *)t_lst->content;
	if (!l_node)
		l_node = build_ltree(shell, new);
	if (token->type == AND_IF)
		l_node = create_and(shell, l_node, build_ltree(shell, new));
	if (token->type == OR)
		l_node = create_and(shell, l_node, build_ltree(shell, new));
	clean_sublist(new);
	return (l_node);
}

t_list	*jump_parenthesis(t_list *tmp)
{
	int		balance;
	t_token	*token;

	tmp = tmp->next;
	balance = 1;
	if (tmp)
		token = (t_token *)tmp->content;
	while (tmp && balance != 0)
	{
		if (tmp)
		{
			token = (t_token *)tmp->content;
			if (token->type == PARENTHESIS && *token->value == ')')
				balance--;
			if (token->type == PARENTHESIS && *token->value == '(')
				balance++;
		}
		if (balance != 0)
			tmp = tmp->next;
	}
	if (tmp)
		tmp = tmp->next;
	return (tmp);
}

void	*get_pipe_subnode(t_shell *shell, void *l_node, t_list *t_lst)
{
	t_list	*new;

	new = NULL;
	new = new_sublist(t_lst->next);
	print_token_lst(new);
	l_node = create_pipe(shell, l_node, build_ltree(shell, new));
	clean_sublist(new);
	return (l_node);
}

t_list	*get_new_token(t_list *tmp)
{
	while (check_token(tmp))
	{
		if (is_parenthesis(tmp))
			tmp = jump_parenthesis(tmp);
		else
			tmp = tmp->next;
	}
	return (tmp);
}
