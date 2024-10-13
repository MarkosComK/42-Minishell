/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:41:18 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/13 15:14:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include <structs.h>

//lexer.c
void	lexer(t_shell *shell, char	*input);
t_list	*tokenize_input(const char *input);
int	handle_redir(t_list **tokens, const char *input, int i);
int	handle_pipe(t_list **tokens, const char *input, int i);
int handle_quotes(t_list **tokens, const char *input, int i);

#endif
