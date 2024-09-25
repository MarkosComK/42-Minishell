/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:20:30 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/25 14:47:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This file contains all the functions that handles the input of of the user
 * either for validations then for parsing the commands.
*/

#ifndef INPUT_H
# define INPUT_H

char	*quote_space_parser(char *argv);
int		counter(char *str, char c);
char	*space_to_minus(char *str);
char	*dequote_single(char *str);

#endif
