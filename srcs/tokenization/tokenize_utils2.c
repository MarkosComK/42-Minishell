/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:24:16 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 20:28:57 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_balance(char *input, int i)
{
	int	balance;

	balance = 1;
	while (input[i] && balance != 0)
	{
		i++;
		if (input[i] && input[i] == '(')
			balance++;
		if (input[i] && input[i] == ')')
			balance--;
	}
	return (i);
}

int	set_hered(t_shell *sh, t_token *new_token, char *input, int i)
{
	new_token->value = ft_strndup(&input[i], 2);
	if (!new_token->value)
		exit_failure(sh, "handle_redir_2");
	new_token->type = HEREDOC;
	return (i + 2);
}
