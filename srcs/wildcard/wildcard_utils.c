/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/11 14:12:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

t_list	*pattern_new(char *str)
{
	char	*dup;
	t_list	*new;

	dup = ft_strdup(str);
	if (!dup)
		return (NULL);
	new = ft_lstnew(dup);
	if (!new)
	{
		free(dup);
		return (NULL);
	}
	return (new);
}

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		i++;
	}
	free(arr);
}

void	ft_free_exp(char ***expansions, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (expansions[i])
			ft_free_arr(expansions[i]);
		i++;
	}
	free(expansions);
}

char	**get_result(char ***exp, int count, int total)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = ft_calloc(total + 1, sizeof(char *));
	if (!result)
		return (ft_free_exp(exp, count), NULL);
	k = 0;
	i = 0;
	while (i < count)
	{
		j = 0;
		while (exp[i][j])
		{
			result[k] = ft_strdup(exp[i][j]);
			if (!result[k])
				return (ft_free_arr(result), ft_free_exp(exp, count), NULL);
			k++;
			j++;
		}
		i++;
	}
	result[k] = NULL;
	return (result);
}
