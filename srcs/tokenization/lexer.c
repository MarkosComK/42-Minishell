/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:38:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 19:00:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_shell *shell, char	*input)
{
	shell->token_lst = NULL;
	tokenize_input(shell, input);
	//expand_tokens(shell);
}
