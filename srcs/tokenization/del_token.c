/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:42:12 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 19:42:22 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	del_token(void *content)
{
	t_token *token;

	token = (t_token *)content;
	if (token)
	{
		free(token->value);
		free(token);
	}
}
