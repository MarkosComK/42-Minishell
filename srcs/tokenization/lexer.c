/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:38:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 17:23:16 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_shell *shell)
{
	int	i;

	i = 0;
	shell->token_lst = NULL;
	while (shell->input[i])
	{
		ft_lstadd_back(&shell->token_lst, ft_lstnew(shell->input[i]));
		i++;
	}
	ft_putstr_fd("init lexer\n", 1);
}
