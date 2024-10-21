/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:41:18 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 16:43:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

# include <structs.h>

typedef enum s_token_type
{
	WORD,
	PIPE,
	APPEND,
	OUTFILE,
	INFILE,
	HEREDOC,
}	t_token_type;

typedef enum s_token_state
{
	GENERAL,
	IN_DQUOTES,
	IN_SQUOTES
}	t_token_state;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	t_token_state	state;
	int				pos;
}	t_token;

//check_token_type.c
t_token_type	token_type(char *value);
//create_token_lst.c
void			tokenize_input(t_shell *shell, char *input);
//t_list	*tokenize_input(const char *input);
int				handle_word_token(t_shell *shell, t_list **token_list, char *input, int i);
int				handle_redir(t_shell *shell, t_list **tokens, char *input, int i);
int				handle_pipe(t_shell *shell, t_list **tokens, char *input, int i);
int				handle_quotes(t_shell *shell, t_list **tokens, char *input, int i);
//lexer.c
void			lexer(t_shell *shell, char	*input);
//set_token_pos.c
void			set_token_pos(t_list *lst);
//tokenize_utils.c
bool			in_quotes(char *input, int i);

#endif
