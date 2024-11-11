/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:07:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:14:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <structs.h>

/*
 * MACROS FOR ERROR MESSAGES
 */
# define SYNTAX_ERROR "minishell: syntax error "
# define SYNTAX_QUOTE "`quote unclosed'"
# define S_QUOTE "`\''"
# define D_QUOTE "`\"'"
# define OPEN_QUOTE "`open quote'"
# define PIPE_ERROR "near unexpected token `|'"
# define REDIR_ERROR_APPEND "near unexpected token `>'"
# define REDIR_ERROR_DAPPEND "near unexpected token `>>'"
# define REDIR_ERROR "near unexpected token `newline'"

//exit_code.c
char	*itoa_exit(t_shell *shell, char **str);
int		last_process(int value);
int		exit_code(int value);
void	exit_status(int status);

//exit_messages.c
void	exit_failure(t_shell *shell, char *function);
void	infile_failure(t_shell *shell, char *file);
void	outfile_failure(t_shell *shell, char *file);
void	is_directory(t_shell *shell, char *path);
void	exec_failure(t_shell *shell, char *cmd, char **argv);

//printers.c
bool	syntax_error_msg(char *str);
void	path_message(t_shell *shell, char *path, char *error_msg);
void	cmd_message(t_shell *shell, char *cmd, char *error_msg);

#endif
