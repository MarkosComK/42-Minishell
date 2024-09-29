/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:38:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/29 16:40:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	lexer(t_shell *shell)
{
	shell->token_lst->content = "teste";
	printf("%s\n", (char *)shell->token_lst->content);
	ft_putstr_fd("init lexer\n", 1);
}
