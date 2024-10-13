/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:38:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/13 14:54:03 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_shell *shell, char	*input)
{
	shell->token_lst = NULL;
	input = ft_strtrim(input, "\t ");
	shell->token_lst = tokenize_input(input);
	free(input);
}
