/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:07:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 12:21:13 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*
 * MACROS FOR ERROR MESSAGES
 */
# define OPEN_QUOTE "`open quote'"
# define SYNTAX_ERROR "minishell: syntax error near unexpected token "
# define PIPE_ERROR "`|'"

//printers.c
bool	syntax_error_msg(char *str);

#endif
