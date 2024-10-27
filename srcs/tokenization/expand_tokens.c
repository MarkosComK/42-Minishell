/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:57:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 16:26:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*check_expansion(char *value, int start)
{
	int		end;
	char	*expansion;
	start++;
	end = start;
	if (!value[start])
		return(free(value), ft_strdup("$"));
	while (value[end] && ft_isalnum(value[end]))
		end++;
	expansion = ft_strndup(&value[start], end);
	free(value);
	printf("string to look: %s\n", expansion);
	return (expansion);
}

void	expand_tokens(t_shell *shell)
{
	t_list	*current;
	char	*value;
	int		i;

	current = shell->token_lst;
	i = 0;
	//print_env_lst(shell->envp);
	while (current)
	{
		value = ((t_token *)current->content)->value;
		while (value[i] && value[i] != '$')
			i++;
		if (value[i] && value[i] == '$')
		{
			((t_token *)current->content)->value = check_expansion(value, i);
		}
		i = 0;
		current = current->next;
	}
	print_token_lst(shell->token_lst);
}

