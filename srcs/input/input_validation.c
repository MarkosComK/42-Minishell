/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:36:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/28 20:25:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	input_validation(char *input)
{
	if (!check_quotes(input))
		ft_putendl_fd(SYNTAX_ERROR OPEN_QUOTE, 2);
	return (false);
}

/*
 * Check if the the amount of quotes are odd or even
 * Even = return true
 *  Odd = return false
 */
bool	check_quotes(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			j++;
		if (i > 0 && str[i] == '\'' && str[i - 1] == '\\')
			j--;
		str++;
	}
	if (j % 2 == 0)
		return (true);
	return (false);
}
