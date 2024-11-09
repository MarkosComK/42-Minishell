/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_andif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:02:01 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 12:07:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	handle_andif(t_shell *shell, char *input, int i)
{
	t_token	*new_token;
	char	*str;

	return (printf("you entered the new token\n"), i);
	str = ft_strdup("");
	if (!str)
		exit_failure(shell, "handle_expand");
	while (input[i])
	{
		if (input[i] == '$' || ft_isquote(input[i]))
			i = prcs_expansion(shell, &str, input, i);
		else
			while (input[i] && (input[i] != '$' && input[i] != '"'))
				str = ft_strjoin_char(str, input[i++]);
		if (ft_isspace(input[i]) || ft_ismeta(input, i))
			break ;
	}
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = str;
	new_token->type = WORD;
	new_token->state = EXPAND;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	return (i);
}
