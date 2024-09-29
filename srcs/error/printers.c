/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:36:29 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/29 13:37:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	syntax_error_msg(char *str)
{
	ft_putstr_fd(SYNTAX_ERROR, 2);
	if (str)
		ft_putendl_fd(str, 2);
}
