/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parenthesis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:39:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 11:26:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	handle_parenthesis(t_shell *shell, char *input, int i)
{
	static bool	valid = false;
	int			start;
	char		*subs;

	printf("you are here:\n");
	if (input[i] == ')')
	{
		i = handle_closing(shell, input, i, valid);
		if (i != -1)
			return (i);
	}
	start = i;
	int balance = 1;
	while (input[i] && balance != 0)
	{
		i++;
		if (input[i] && input[i] == '(')
			balance++;
		if (input[i] && input[i] == ')')
			balance--;
	}
	subs = ft_substr(&input[start + 1], 0, i - start - 1);
	printf("subs: %s\n", subs);
	valid = validate_subs(subs);
	free(subs);
	i = handle_opening(shell, input, start, valid);
	if (i != -1)
		return (i);
	if (input[start] && input[start] == '(')
		start++;
	while (ft_isspace(input[start]))
		start++;
	return (start);
}

int	handle_closing(t_shell *shell, char *input, int i, bool valid)
{
	t_token	*new_token;
	char	*str;

	if (input[i] == ')' && valid)
	{
		str = ft_strdup(")");
		i++;
		if (!str)
			exit_failure(shell, "handle_parenthesis");
		new_token = ft_calloc(1, sizeof(t_token));
		new_token->value = str;
		new_token->type = PARENTHESIS;
		new_token->state = GENERAL;
		ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
		while (ft_isspace(input[i]))
			i++;
		return (i);
	}
	else
	{
		i = jump_spaces(input, i);
		printf("%c\n", input[i]);
		return (i);
	}
	return (-1);
}

bool	validate_subs(char *subs)
{
	char	*tkns;
	int		j;
	int		i;

	tkns = "|&";
	j = 0;
	i = 0;
	if (!subs || i < 0)
		return (false);
	while (subs[i])
	{
		j = 0;
		while (tkns[j])
		{
			if (subs[i] && subs[i] == tkns[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	handle_opening(t_shell *shell, char *input, int i, bool valid)
{
	t_token		*new_token;
	char		*str;

	if (valid)
	{
		if (input[i] == '(')
			str = ft_strdup("(");
		if (input[i] == ')')
			str = ft_strdup(")");
		i++;
		if (!str)
			exit_failure(shell, "handle_parenthesis");
		new_token = ft_calloc(1, sizeof(t_token));
		new_token->value = str;
		new_token->type = PARENTHESIS;
		new_token->state = GENERAL;
		ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
		while (ft_isspace(input[i]))
			i++;
		return (i);
	}
	return (-1);
}

int	jump_spaces(char *input, int i)
{
	i++;
	while (ft_isspace(input[i]))
		i++;
	return (i);
}
