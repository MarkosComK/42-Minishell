/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:58:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/28 12:58:28 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}

int	ft_flag(char c, int *i, bool flag)
{
	if (c == '"')
	{
		*i = *i + 1;
		return (!flag);
	}
	return (flag);
}

t_token	*create_token(t_shell *shell, char *str)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (!new_token)
		exit_failure(shell, "create_token");
	new_token->value = str;
	new_token->type = WORD;
	new_token->state = GENERAL;
	if (!ft_strcmp(str, ""))
		new_token->state = EXPAND;
	return (new_token);
}
