/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:38:47 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 18:07:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*skip_if(t_list *tmp)
{
	while (tmp && ((t_token *)tmp->content)->type != PIPE)
	{
		tmp = tmp->next;
		if (tmp && ((t_token *)tmp->content)->type == AND_IF)
			break ;
	}
	return (tmp);
}

t_list	*skip_else(t_list *tmp)
{
	tmp = tmp->next;
	while (tmp && ((t_token *)tmp->content)->type != PIPE)
	{
		tmp = tmp->next;
		if (tmp && ((t_token *)tmp->content)->type == AND_IF)
			break ;
	}
	return (tmp);
}

t_list	*check_word(t_list **current, char **argv, int *i)
{
	if (*current && ((t_token *)(*current)->content)->state == EXPAND
		&& ft_strlen(((t_token *)(*current)->content)->value) == 0)
	{
		*current = (*current)->next;
		return (*current);
	}
	argv[*i] = ((t_token *)(*current)->content)->value;
	*current = (*current)->next;
	(*i)++;
	return (*current);
}

t_list	*check_w_args(t_list *tkn_lst, int *args)
{
	if (tkn_lst && ((t_token *)tkn_lst->content)->type == WORD)
	{
		if (((t_token *)tkn_lst->content)->state == EXPAND
			&& ft_strlen(((t_token *)tkn_lst->content)->value) == 0)
		{
			return (tkn_lst->next);
		}
		(*args)++;
	}
	return (tkn_lst->next);
}
