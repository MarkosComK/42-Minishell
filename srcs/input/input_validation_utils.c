/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:16:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:16:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	ft_isquote(char c)
{
	if (c == '\'' || c == '"')
		return (true);
	return (false);
}

int	ft_isredir(char *c)
{
	if (c[0] == '>')
	{
		if (c[1] == '>')
			return (2);
		return (1);
	}
	if (c[0] == '<')
	{
		if (c[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

void	toggle_quotes(char c, bool *in_single_quote, bool *in_double_quote)
{
	if (c == '\'' && !*in_double_quote)
		*in_single_quote = !*in_single_quote;
	else if (c == '\"' && !*in_single_quote)
		*in_double_quote = !*in_double_quote;
}

int	jump_quotes(char *str, int i)
{
	if (str[i] && ft_isquote(str[i]))
	{
		i++;
		while (str[i] && !ft_isquote(str[i]))
			i++;
	}
	return (i);
}

bool	handle_redir_error(char *str, int *i, int redir_len)
{
	char	*error_msg;

	if (str[*i + 1] == '|')
	{
		syntax_error_msg("near unexpected token `|'");
		return (false);
	}
	*i += redir_len;
	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (ft_isredir(&str[*i]))
	{
		if (str[*i] == '>' && str[*i + 1] == '>')
			error_msg = "near unexpected token `>>'";
		else if (str[*i] == '<')
			error_msg = "near unexpected token `<'";
		else
			error_msg = "near unexpected token `>'";
		syntax_error_msg(error_msg);
		return (false);
	}
	return (true);
}
