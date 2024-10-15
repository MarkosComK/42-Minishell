/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:41:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/13 15:18:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	tokenize_input(t_shell *shell, char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		while (ft_isspace(input[i]))
			i++;
		i = handle_word_token(&shell->token_lst, input, i);
		if (input[i] == '|' || input[i] == '>' || input[i] == '<')
		{
			if (input[i] == '>' && input[i + 1] == '>')
				i = handle_redir(&shell->token_lst, input, i);
			else
				i = handle_pipe(&shell->token_lst, input, i);
		}
	}
}

int	handle_word_token(t_list **token_list, char *input, int i)
{
	t_token	*new_token;
	int		start;

	start = i;
	new_token = ft_calloc(1, sizeof(t_token));
	while (input[i] && !ft_isspace(input[i]) && input[i] != '|'
		&& input[i] != '>' && input[i] != '<'
		&& input[i] != '"' && input[i] != '\'')
	{
		i++;
	}
	new_token->value = ft_strndup(input + start, i - start);
	new_token->type = WORD;
	ft_lstadd_back(token_list, ft_lstnew(new_token));
	return (i);
}

int	handle_redir(t_list **tokens, const char *input, int i)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = ft_strndup(&input[i], 2);
	ft_lstadd_back(tokens, ft_lstnew(new_token));
	return (i += 2);
}

int	handle_pipe(t_list **tokens, const char *input, int i)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = ft_strndup(&input[i], 1);
	new_token->type = PIPE;
	ft_lstadd_back(tokens, ft_lstnew(new_token));
	i++;
	return (i);
}
/*
int	handle_quotes(t_list *token_lst, t_token **token, const char *input, int i)
{
	char	quote;
	int		start;

	quote = input[i++];
	start = i;
	while (input[i] && input[i] != quote)
		i++;
	token->value = ft_substr(input, start, i - start);
	ft_lstadd_back(&token_lst, token);
	free(value);
	return (i + 1);
}
*/
