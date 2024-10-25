/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:07:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 16:21:45 by marsoare         ###   ########.fr       */
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

//printers.c
bool	syntax_error_msg(char *str);
void	exit_failure(t_shell *shell, char *function);
void	infile_failure(t_shell *shell, char *file);
void	is_directory(t_shell *shell, char *path);
void	exec_failure(t_shell *shell, char *cmd);

#endif
