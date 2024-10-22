/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:15:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 16:50:33 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <structs.h>

//printers.c
void	print_lst(t_list *list);
void	print_token_lst(t_list *lst);
void	print_cmd_lst(t_shell *shell);

#endif
