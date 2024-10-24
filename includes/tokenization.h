/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:41:18 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 21:21:50 by marsoare         ###   ########.fr       */
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
int				handle_word_token(t_shell *shell, char *input, int i);
int				handle_redir(t_shell *shell, char *input, int i);
int				handle_pipe(t_shell *shell, char *input, int i);
int				handle_quotes(t_shell *shell, char *input, int i);
//ft_joinstrs.c
int				join_strs(t_shell *shell, char **str, char *input, int i);
int				handle_quoted_str(t_shell *shell, char **str, char *input, int i);
int				handle_nonquoted_str(t_shell *shell, char **str, char *input, int i);
//lexer.c
void			lexer(t_shell *shell, char	*input);
//remove_qutes.c
void	remove_quotes(t_shell *shell);
//set_token_pos.c
void			set_token_pos(t_list *lst);
//tokenize_utils.c
bool			in_quotes(char *input, int i);
bool			ft_ismeta(char *str, int i);
int				set_append(t_shell *sh, t_token *new_token, char *input, int i);
int				set_simple(t_shell *sh, t_token *new_token, char *input, int i);

#endif
