/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:46:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/15 16:14:43 by marsoare         ###   ########.fr       */
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

t_list	*generate_matches(t_dirent *entry, char *token, t_list *matches)
{
	DIR			*dir;
	t_list		*new;

	dir = opendir(".");
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (entry->d_name[0] == '.' && token[0] != '.')
		{
			entry = readdir(dir);
			continue ;
		}
		if (match_pattern(token, entry->d_name))
		{
			new = pattern_new(entry->d_name);
			if (!new)
				return (ft_lstclear(&matches, free), closedir(dir), NULL);
			ft_lstadd_back(&matches, new);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (matches);
}

char	**validate_matches(char *token)
{
	char	**result;

	result = ft_calloc(2, sizeof(char *));
	if (!result)
		return (NULL);
	result[0] = ft_strdup(token);
	if (!result[0])
		return (free(result), NULL);
	result[1] = NULL;
	return (result);
}
