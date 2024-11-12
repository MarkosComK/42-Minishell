/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:39:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 11:26:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	handle_parenthesis(t_shell *shell, char *input, int i)
{
	t_token	*new_token;
	char	*str;

	if (input[i] == '(')
		str = ft_strdup("(");
	if (input[i] == ')')
		str = ft_strdup(")");
	i++;
	if (!str)
		exit_failure(shell, "handle_parenthesis");
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = str;
	new_token->type = PARENTHESIS;
	new_token->state = GENERAL;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	return (i);
}
