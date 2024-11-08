/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:37:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 13:46:05 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*heredoc_expand(t_shell *shell, char *line)
{
	char	*str;
	int		i;

	str = ft_strdup("");
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' || ft_isquote(line[i]))
			i = prcs_expansion(shell, &str, line, i);
		else
			while (line[i] && (line[i] != '$' && line[i] != '"'))
				str = ft_strjoin_char(str, line[i++]);
		if (ft_isspace(line[i]) || ft_ismeta(line, i))
			break ;
	}
	while (ft_isspace(line[i]))
		i++;
	return (str);
}
