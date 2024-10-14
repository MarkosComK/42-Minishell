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

typedef enum s_token_type
{
	WORD,
	PIPE,
	APPEND,
	OUTFILE,
	INFILE,
}	t_token_type;

typedef enum s_token_state
{
	GENERAL,
	IN_DQUOTES,
	IN_SQUOTES
}	t_token_state;

typedef struct s_token
{
	char			*content;
	t_token_type	type;
	t_token_state	state;
	int				pos;
}	t_token;

//create_token_lst.c
t_list	*tokenize_input(const char *input);
int	handle_redir(t_list **tokens, const char *input, int i);
int	handle_pipe(t_list **tokens, const char *input, int i);
int handle_quotes(t_list **tokens, const char *input, int i);
int	handle_word_token(t_list **tokens, const char *input, int i);
//lexer.c
void	lexer(t_shell *shell, char	*input);

#endif
