/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:38:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/01 17:11:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_shell *shell, char	*input)
{
	int	i;

	i = 0;
	shell->token_lst = NULL;
	input = ft_strtrim(input, "\t ");
	shell->input = ft_split_dlim(input, METACHARS);
	while (shell->input[i])
	{
		ft_lstadd_back(&shell->token_lst, ft_lstnew(shell->input[i]));
		i++;
	}
	free(input);
}
