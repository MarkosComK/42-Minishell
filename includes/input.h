/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:20:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 12:19:01 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This file contains all the functions that handles the input of the user
 * either for validations or parsing the commands.
*/

#ifndef INPUT_H
# define INPUT_H

# include <structs.h>

//input_validation.c
bool	input_validation(t_shell *shell);
bool	check_quotes(char *str);
bool	check_quotes_pos(char *str);
bool	check_pipes(char *str);
bool	check_redirs(char *str);

//input_validation.c
bool	ft_isquote(char c);

//quote_parser.c
char	*quote_space_parser(char *argv);
int		counter(char *str, char c);
char	*space_to_minus(char *str);
char	*dequote_single(char *str);

#endif
