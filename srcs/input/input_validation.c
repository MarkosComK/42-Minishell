/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:36:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/28 20:38:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	input_validation(char *input)
{
	while (*input == ' ' || *input =='\t' || *input == '\v')
		input++;
	if (!check_quotes(input))
		ft_putendl_fd(SYNTAX_ERROR OPEN_QUOTE, 2);
	else if (!check_pipes(input))
		ft_putendl_fd(SYNTAX_ERROR PIPE, 2);
	return (false);
}

/*
 * Check if the the amount of quotes are odd or even
 * (Every opened quote must close)
 * Even = return true
 *  Odd = return false
 */
bool	check_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\\' || str[i] == '"')
			j++;
		i++;
	}
	if (j % 2 == 0)
		return (true);
	return (false);
}

/*
 * Check if the the pipes are correctly placed
 * (Pipes cannot have space between or start at the input)
 */
bool	check_pipes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '|')
			return (false);
		i++;
	}
	return (true);
}
