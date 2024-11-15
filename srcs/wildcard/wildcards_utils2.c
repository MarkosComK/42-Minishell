/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:46:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:38 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	***get_expand(char **argv, int size)
{
	char	***expanded;
	int		i;

	expanded = ft_calloc(size + 1, sizeof(char **));
	if (!expanded)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '*'))
			expanded[i] = expand_wildcard(argv[i]);
		else
		{
			expanded[i] = ft_calloc(2, sizeof(char *));
			expanded[i][0] = ft_strdup(argv[i]);
		}
		if (!expanded[i])
			return (ft_free_exp(expanded, i), NULL);
		i++;
	}
	return (expanded);
}
