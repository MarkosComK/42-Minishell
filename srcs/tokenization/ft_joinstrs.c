/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:12:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 21:19:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	join_strs(char **str, char *input, int i)
{
	if (ft_isquote(input[i]))
	{
		i = handle_quoted_str(str, input, i);
	}
	else
	{
		i = handle_nonquoted_str(str, input, i);
	}
	return (i);
}

int	handle_quoted_str(char **str, char *input, int i)
{
	char	*join;
	char	quote;
	int		start;
	char	*tmp;

	quote = input[i++];
	start = i;
	while (input[i] != quote && input[i] != '\0')
		i++;
	join = ft_substr(input, start, i - start);
	tmp = *str;
	*str = ft_strjoin(*str, join);
	free(tmp);
	free(join);
	i++;
	return (i);
}

int	handle_nonquoted_str(char **str, char *input, int i)
{
	char	*join;
	int		start;
	char	*tmp;

	start = i;
	while (input[i] && !ft_isquote(input[i])
		&& !ft_isspace(input[i]) && !ft_ismeta(input, i))
		i++;
	join = ft_substr(input, start, i - start);
	tmp = *str;
	*str = ft_strjoin(*str, join);
	free(tmp);
	free(join);
	return (i);
}

/*
int	join_strs(char **str, char *input, int i)
{
	char	*join;
	char	quote;
	int		start;
	char	*tmp;

	if (ft_isquote(input[i]))
	{
		quote = input[i++];
		start = i;
		while (input[i] != quote && input[i] != '\0')
			i++;
		join = ft_substr(input, start, i - start);
		tmp = *str;
		*str = ft_strjoin(*str, join);
		free(tmp);
		free(join);
		i++;
	}
	else
	{
		start = i;
		while (input[i] && !ft_isquote(input[i])
			&& !ft_isspace(input[i]) && !ft_ismeta(input, i))
			i++;
		join = ft_substr(input, start, i - start);
		tmp = *str;
		*str = ft_strjoin(*str, join);
		free(tmp);
		free(join);
	}
	return (i);
}
*/
