/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/11 14:12:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**process_wildcards(char **argv)
{
	char	***expanded;
	char	**result;
	int		i;

	i = 0;

	while (argv[i])
		i++;
	expanded = ft_calloc(i + 1, sizeof(char **));
	if (!expanded)
		return (argv);
	i = -1;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], '*'))
			expanded[i] = expand_wildcard(argv[i]);
		else
		{
			expanded[i] = ft_calloc(2, sizeof(char *));
			expanded[i][0] = ft_strdup(argv[i]);
		}
		if (!expanded[i])
			return (ft_free_expansion(expanded, i), argv);
	}
	result = merge_expansions(expanded, i);
	if (!result)
		return (ft_free_expansion(expanded, i), argv);
	return (result);
}

char	**expand_wildcard(char *token)
{
	t_list	*matches;
	char	**result;

	matches = get_matches(token);
	result = pattern_to_arr(matches, token);
	ft_lstclear(&matches, free);
	return (result);
}

char	**merge_expansions(char ***expanded, int count)
{
	char	**result;
	int		total;
	int		i;
	int		j;
	int		k;

	total = 0;
	i = -1;
	i = -1;
	while (++i < count)
		total += ft_arrlen(expanded[i]);
	result = ft_calloc(total + 1, sizeof(char *));
	if (!result)
		return (ft_free_expansion(expanded, count), NULL);
	k = 0;
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (expanded[i][++j])
		{
			result[k] = ft_strdup(expanded[i][j]);
			if (!result[k])
			{
				ft_free_arr(result);
				ft_free_expansion(expanded, count);
				return (NULL);
			}
			k++;
		}
	}
	result[k] = NULL;
	i = 0;
	return (ft_free_expansion(expanded, count), result);
}

int	match_pattern(char *pattern, char *str)
{
	if (*pattern == '*')
	{
		while (*pattern == '*')
			pattern++;
		if (!*pattern)
			return (1);
		while (*str)
		{
			if (match_pattern(pattern, str))
				return (1);
			str++;
		}
		return (match_pattern(pattern, str));
	}
	if (!*pattern && !*str)
		return (1);
	if (*pattern == *str)
		return (match_pattern(pattern + 1, str + 1));
	return (0);
}

char	**pattern_to_arr(t_list *matches, char *token)
{
	char	**result;
	size_t	size;
	size_t	i;
	t_list	*curr;

	if (!matches)
	{
		result = ft_calloc(2, sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = ft_strdup(token);
		if (!result[0])
			return (free(result), NULL);
		result[1] = NULL;
		return (result);
	}
	size = ft_lstsize(matches);
	result = ft_calloc(size + 1, sizeof(char *));
	if (!result)
		return (NULL);
	curr = matches;
	i = 0;
	while (curr)
	{
		result[i] = ft_strdup(curr->content);
		if (!result[i])
			return (ft_free_arr(result), NULL);
		curr = curr->next;
		i++;
	}
	result[i] = NULL;
	return (result);
}



/*
char	**process_wildcards(char **argv)
{
	char	***expanded;
	char	**result;
	size_t	i;

	if (!argv)
		return (NULL);
	i = 0;
	while (argv[i])
		i++;
	expanded = ft_calloc(i + 1, sizeof(char **));
	if (!expanded)
		return (argv);
	i = -1;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], '*'))
			expanded[i] = expand_wildcard(argv[i]);
		else
		{
			expanded[i] = ft_calloc(2, sizeof(char *));
			if (!expanded[i])
			{
				ft_free_expansion(expanded, i);
				return (argv);
			}
			expanded[i][0] = ft_strdup(argv[i]);
			if (!expanded[i][0])
			{
				ft_free_expansion(expanded, i);
				return (argv);
			}
			expanded[i][1] = NULL;
		}
		if (!expanded[i])
			return (ft_free_expansion(expanded, i), NULL);
	}
	result = merge_expansions(expanded, i);
	if (!result)
	{
		return (argv);
	}
	ft_free_arr(argv);
	return (result);
}
*/
