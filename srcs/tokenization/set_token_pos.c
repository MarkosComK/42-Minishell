/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:39:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 16:43:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_token_pos(t_list *lst)
{
	t_token	*token;
	int		i;

	i = 0;
	while (lst)
	{
		token = (t_token *) lst->content;
		token->pos = i;
		lst = lst->next;
		i++;
	}
}
