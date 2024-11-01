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

//input_validation_utils.c
bool	ft_isquote(char c);
int		ft_isredir(char *c);
void	toggle_quotes(char c, bool *in_single_quote, bool *in_double_quote);
int		jump_quotes(char *str, int i);

#endif
