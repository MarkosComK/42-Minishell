/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:33:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 18:41:38 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_quotes(t_shell *shell)
{
	t_list	*token_list;
	
	token_list = shell->token_lst;
	print_token_lst(token_list);
	while (token_list)
	{
		printf("before remove: %s\n", ((t_token *)token_list->content)->value);
		token_list = token_list->next;
	}
}
