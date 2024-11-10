/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:15:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 10:16:45 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	handle_or(t_shell *shell, char *input, int i)
{
	t_token	*new_token;
	char	*str;

	str = ft_strdup("||");
	i += 2;
	if (!str)
		exit_failure(shell, "handle_expand");
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = str;
	new_token->type = OR;
	new_token->state = GENERAL;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	return (i);
}
