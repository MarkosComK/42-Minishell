/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinstrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:12:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 21:24:49 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	join_strs(t_shell *shell, char **str, char *input, int i)
{
	if (ft_isquote(input[i]))
	{
		i = handle_quoted_str(shell, str, input, i);
	}
	else
	{
		i = handle_nonquoted_str(shell, str, input, i);
	}
	return (i);
}

int	handle_quoted_str(t_shell *shell, char **str, char *input, int i)
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
	if (!join)
		exit_failure(shell, "handle_quotes_str");
	tmp = *str;
	*str = ft_strjoin(*str, join);
	free(tmp);
	free(join);
	if (!*str)
		exit_failure(shell, "handle_quotes_str_1");
	i++;
	return (i);
}

int	handle_nonquoted_str(t_shell *shell, char **str, char *input, int i)
{
	char	*join;
	int		start;
	char	*tmp;

	start = i;
	while (input[i] && !ft_isquote(input[i])
		&& !ft_isspace(input[i]) && !ft_ismeta(input, i))
		i++;
	join = ft_substr(input, start, i - start);
	if (!join)
		exit_failure(shell, "handle_nonquotes_str");
	tmp = *str;
	*str = ft_strjoin(*str, join);
	free(tmp);
	free(join);
	if (!*str)
		exit_failure(shell, "handle_nonquotes_str_1");
	return (i);
}
