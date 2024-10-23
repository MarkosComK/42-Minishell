/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:36:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 12:49:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	input_validation(t_shell *shell)
{
	if (shell->input[0] == '\0')
		return (true);
	shell->trim_input = ft_strtrim(shell->input, "\t ");
	if (!shell->trim_input)
		exit_failure(shell, "input_validation");
	if (shell->trim_input[0] == '\0')
		return (true);
	if (!check_pipes(shell->trim_input))
		return (syntax_error_msg(PIPE_ERROR));
	if (!check_quotes(shell->trim_input))
		return (syntax_error_msg(OPEN_QUOTE));
	if (!check_quotes_pos(shell->trim_input))
		return (syntax_error_msg(SYNTAX_QUOTE));
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
	int		i;
	char	current_quote;

	i = 0;
	current_quote = 0;
	while (str[i])
	{
		if (ft_isquote(str[i]))
		{
			if (current_quote == 0)
				current_quote = str[i];
			else if (str[i] == current_quote)
				current_quote = 0;
		}
		i++;
	}

	return (current_quote == 0);
}

// this function prevents minishell to run with that case below
// "'example"'
// "'ls"'
bool	check_quotes_pos(char *str)
{
	int		i;
	char	quote;
	bool	quote_found;

	i = -1;
	quote = 0;
	quote_found = false;
	while (str[++i])
	{
		if (ft_isquote(str[i]))
		{
			if (!quote_found)
			{
				quote = str[i];
				quote_found = true;
			}
			else if (str[i] == quote)
			{
				quote = 0;
				quote_found = false;
			}
		}
	}
	return (!quote_found);
}
/*
bool	check_quotes_pos(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] && ft_isquote(str[i]) && !ft_isquote(str[i + 1]))
		{
			quote = str[i];
			break ;
		}
		i++;
	}
	i++;
	while (str[i] && !ft_isquote(str[i]))
		i++;
	if (str[i] != quote)
		return (false);
	return (true);
}
*/
/*
 * Check if the the pipes are correctly placed
 * (Pipes cannot have space between them OR start at the input)
 * Input cannot end with a pipe
 */
bool	check_pipes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '|'
			|| (str[i] == '|' && str[i + 1] == ' ' && str[i + 2] == '|'))
			return (false);
		if (str[i] == '|' && str[i + 1] == '|')
			return (false);
		i++;
	}
	if (str[ft_strlen(str) - 1] == '|')
		return (false);
	return (true);
}
