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

t_list	*tokenize_input(const char *input)
{
	t_list	*tokens = NULL;
	int i = 0;

	while (input[i])
	{
		while(ft_isspace(input[i]))
			i++;
		if (input[i] == '"' || input[i] == '\'')
			i = handle_quotes(&tokens, input, i);
		else if (input[i] == '|' || input[i] == '>' || input[i] == '<')
		{
			if (input[i] == '>' && input[i + 1] == '>')
				i = handle_redir(&tokens, input, i);
			else
				i = handle_pipe(&tokens, input, i);
		}
		else
		{
			i = handle_word_token(&tokens, input, i);
		}
	}
	return tokens;
}

int	handle_quotes(t_list **tokens, const char *input, int i)
{
	char quote = input[i++];
	int start = i;
	char *token;

	while (input[i] && input[i] != quote)
		i++;
	token = ft_substr(input, start, i - start);
	ft_lstadd_back(tokens, ft_lstnew(ft_strdup(token)));
	free(token);
	return i + 1;
}

int	handle_redir(t_list **tokens, const char *input, int i)
{
	char	*token;

	token = ft_strndup(&input[i], 2);
	ft_lstadd_back(tokens, ft_lstnew(ft_strdup(token)));
	free(token);
	return (i += 2);
}

int	handle_pipe(t_list **tokens, const char *input, int i)
{
	char	*token;

	token = ft_strndup(&input[i], 1);
	ft_lstadd_back(tokens, ft_lstnew(ft_strdup(token)));
	i++;
	free(token);
	return (i);
}

int	handle_word_token(t_list **tokens, const char *input, int i)
{
	int start;
	char *token;

	start = i;
	while (input[i] && !ft_isspace(input[i]) && input[i] != '|' && input[i] != '>' && input[i] != '<' && input[i] != '"' && input[i] != '\'')
	{
			i++;
	}
	token = ft_strndup(input + start, i - start);
	ft_lstadd_back(tokens, ft_lstnew(ft_strdup(token)));
	free(token);
	return i;
}
