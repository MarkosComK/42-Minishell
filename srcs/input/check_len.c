/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:54:26 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 18:22:45 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_line_len(char *line)
{
	if (ft_strlen(line) > 200)
		return (ft_putendl_fd(LINE_ERROR, 2), false);
	return (true);
}
