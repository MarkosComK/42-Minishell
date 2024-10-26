/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:36:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 05:06:01 by marsoare         ###   ########.fr       */
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
	if (!check_redirs(shell->trim_input))
		return (syntax_error_msg(REDIR_ERROR));
	return (false);
}

/*
 * Check if all quotes in the string are properly matched.
 * It tracks the opening and closing of single and double quotes.
 * If every opened quote has a corresponding closing quote,
 * the function returns true (indicating valid quotes).
 * If there are unmatched quotes, it returns false (indicating invalid quotes).
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

/*
 * This function checks if there are unmatched quotes in the string.
 * It ensures that every opening quote has a corresponding closing quote.
 * If there are unmatched quotes at the end of the string,
 * the function returns false (indicating that the command should not run).
 * Examples that would prevent minishell from running:
 * - "'example"'
 * - "'ls"'
 */
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
 * Check if the the pipes are correctly placed
 * (Pipes cannot have space between them OR start at the input)
 * Input cannot end with a pipe
 */
bool check_pipes(char *str)
{
	int i;

	i = 0;
	if (str[i] == '|')
		return false;
	while (str[i])
	{
		while (isspace(str[i]))
			i++;
		if (str[i] == '|')
		{
			if (str[i + 1] == '|' || str[i + 1] == '\0')
				return false;
			i++;
			while (isspace(str[i]))
				i++;
			if (str[i] == '|')
				return false;
		}
		else
			i++;
	}
	if (str[i - 1] == '|')
		return false;
	return true;
}

bool	check_redirs(char *str)
{
	int		i;
	int		redir_len;

	i = 0;
	while (str[i])
	{
		redir_len = ft_isredir(&str[i]);
		if (redir_len > 0)
		{
			i += redir_len;
			while (str[i] && ft_isspace(str[i]))
				i++;
			if (ft_isredir(&str[i]))
				return (false);
			if (!str[i])
				return (false);
			continue ;
		}
		if (str[i])
			i++;
	}
	return (true);
}
