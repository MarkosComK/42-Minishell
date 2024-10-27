/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:57:42 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 17:34:58 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*check_expansion(t_shell *shell, char *value, int start)
{
	int		end;
	char	*expansion;
	t_list	*current;
	start++;
	end = start;
	if (!value[start])
		return(free(value), ft_strdup("$"));
	while (value[end] && ft_isprint(value[end]))
		end++;
	expansion = ft_strndup(&value[start], end);
	start = ft_strlen(expansion);
	if (expansion)
	{
		current = shell->envp;
		while (current)
		{
			if (!ft_strncmp(current->content, expansion, start))
			{
				free(expansion);
				expansion = ft_strdup(&current->content[start + 1]);
			}
			current = current->next;
		}
		
	}
	return (free(value), expansion);
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
			((t_token *)current->content)->value = check_expansion(shell, value, i);
		i = 0;
		current = current->next;
	}
	print_token_lst(shell->token_lst);
}

