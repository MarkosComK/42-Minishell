/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:41:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 16:44:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	tokenize_input(t_shell *shell, char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			i = handle_quotes(&shell->token_lst, input, i);
		else if (input[i] == '|')
			i = handle_pipe(&shell->token_lst, input, i);
		else if (input[i] == '>' || input[i] == '<')
			i = handle_redir(&shell->token_lst, input, i);
		else
			i = handle_word_token(&shell->token_lst, input, i);
		set_token_pos(shell->token_lst);
	}
}

int	handle_word_token(t_list **token_list, char *input, int i)
{
	t_token	*new_token;
	int		start;

	start = i;
	new_token = ft_calloc(1, sizeof(t_token));
	while (input[i] && !ft_isspace(input[i]) && input[i] != '|'
		&& input[i] != '>' && input[i] != '<')
	{
		i++;
	}
	new_token->value = ft_strndup(input + start, i - start);
	new_token->type = WORD;
	new_token->state = GENERAL;
	ft_lstadd_back(token_list, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	return (i);
}

int	handle_redir(t_list **tokens, char *input, int i)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (input[i] == '>' && input[i + 1] == '>')
	{
		new_token->value = ft_strndup(&input[i], 2);
		new_token->type = APPEND;
		i += 2;
	}
	else
	{
		new_token->value = ft_strndup(&input[i], 1);
		if (input[i] == '<')
			new_token->type = INFILE;
		else
			new_token->type = OUTFILE;
		i++;
	}
	new_token->state = GENERAL;
	ft_lstadd_back(tokens, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	return (i);
}

int	handle_pipe(t_list **tokens, char *input, int i)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = ft_strndup(&input[i], 1);
	new_token->type = PIPE;
	new_token->state = GENERAL;
	ft_lstadd_back(tokens, ft_lstnew(new_token));
	i++;
	while (ft_isspace(input[i]))
		i++;
	return (i);
}

int	handle_quotes(t_list **tokens, char *input, int i)
{
	t_token	*new_token;
	char	quote;
	int		start;

	new_token = ft_calloc(1, sizeof(t_token));
	quote = input[i++];
	start = i;
	while (input[i] && input[i] != quote)
		i++;
	new_token->value = ft_substr(input, start, i - start);
	new_token->type = WORD;
	if (quote == '"')
		new_token->state = IN_DQUOTES;
	else if (quote == '\'')
		new_token->state = IN_SQUOTES;
	ft_lstadd_back(tokens, ft_lstnew(new_token));
	i++;
	while (ft_isspace(input[i]))
		i++;
	return (i);
}
