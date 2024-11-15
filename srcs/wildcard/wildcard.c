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
		{
			free(result);
			return (NULL);
		}
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

char	**merge_expansions(char ***expanded, int count)
{
	char	**result;
	int		total;
	int		i;
	int		j;
	int		k;

    printf("\n[MERGE_EXPANSIONS] Iniciando com count=%d\n", count);
	total = 0;
	i = -1;
    i = -1;
    while (++i < count)
    {
        printf("  Contando array %d: ", i);
        if (expanded[i])
            printf("%d elementos\n", ft_arrlen(expanded[i]));
        else
            printf("NULL\n");
        total += ft_arrlen(expanded[i]);
    }
    printf("[MERGE_EXPANSIONS] Total de elementos: %d\n", total);
	result = ft_calloc(total + 1, sizeof(char *));
	if (!result)
	{
        printf("[MERGE_EXPANSIONS] Falha na alocação\n");		
		ft_free_expansion(expanded, count);
		return (NULL);
	}
	k = 0;
	i = -1;
	while (++i < count)
	{
		j = -1;
		while (expanded[i][++j])
		{
            printf("  Copiando expanded[%d][%d] = '%s' para result[%d]\n", 
                   i, j, expanded[i][j], k);			
			result[k] = ft_strdup(expanded[i][j]);
			if (!result[k])
			{
				printf("  Falha na cópia\n");
				ft_free_arr(result);
				ft_free_expansion(expanded, count);
				return (NULL);
			}
			k++;
		}
	}
	result[k] = NULL;
    printf("[MERGE_EXPANSIONS] Resultado final:\n");
    i = 0;
    while (result[i])
    {
        printf("  result[%d] = '%s'\n", i, result[i]);
        i++;
    }
	ft_free_expansion(expanded, count);
    printf("[MERGE_EXPANSIONS] Finalizado\n\n");	
	return (result);
}

char	**expand_wildcard(char *token)
{
	t_list	*matches;
	char	**result;

    printf("\n[EXPAND_WILDCARD] Expandindo '%s'\n", token);
	matches = get_matches(token);
	printf("[EXPAND_WILDCARD] Matches encontrados:\n");
	if (matches)
    {
        t_list *temp = matches;
        while (temp)
        {
            printf("  -> '%s'\n", (char *)temp->content);
            temp = temp->next;
        }
    }
    else
	{
        printf("  -> Nenhum match encontrado\n");
	}
	result = pattern_to_arr(matches, token);
	printf("[EXPAND_WILDCARD] Resultado da conversão:\n");
	if (result)
    {
        int i = 0;
        while (result[i])
        {
            printf("  result[%d] = '%s'\n", i, result[i]);
            i++;
        }
    }
    else
	{
        printf("  -> Falha na conversão\n");
	}
	ft_lstclear(&matches, free);
    printf("[EXPAND_WILDCARD] Finalizado\n\n");	
	return (result);
}

char	**process_wildcards(char **argv)
{
	char	***expanded;
	char	**result;
	int		i;

	i = 0;

	printf("\n[PROCESS_WILDCARDS] Iniciando...\n");
	while (argv[i])
		i++;
	printf("[PROCESS_WILDCARDS] Total de argumentos: %d\n", i);
	expanded = ft_calloc(i + 1, sizeof(char **));
    if (!expanded)
    {
        printf("[PROCESS_WILDCARDS] Falha na alocação inicial\n");
        return (argv);
    }
	i = -1;
	while (argv[++i])
	{
		printf("[PROCESS_WILDCARDS] Processando argv[%d]: '%s'\n", i, argv[i]);
		if (ft_strchr(argv[i], '*'))
        {
            printf("  -> Contém wildcard, expandindo...\n");
            expanded[i] = expand_wildcard(argv[i]);
        }
		else
		{
			printf("  -> Sem wildcard, copiando...\n");
			expanded[i] = ft_calloc(2, sizeof(char *));
			expanded[i][0] = ft_strdup(argv[i]);
		}
		if (!expanded[i])
            {
                printf("  -> Falha na alocação\n");
                ft_free_expansion(expanded, i);
                return (argv);
            }
		printf("  -> Resultado:\n");
        for (int j = 0; expanded[i][j]; j++)
            printf("    expanded[%d][%d] = '%s'\n", i, j, expanded[i][j]);	
	}
    printf("[PROCESS_WILDCARDS] Mesclando resultados...\n");	
	result = merge_expansions(expanded, i);
    if (!result)
    {
        printf("[PROCESS_WILDCARDS] Falha na mesclagem\n");
        return (argv);
    }
	
    printf("[PROCESS_WILDCARDS] Resultado final:\n");
    i = 0;
    while (result[i])
    {
        printf("  result[%d] = '%s'\n", i, result[i]);
        i++;
    }
    printf("[PROCESS_WILDCARDS] Finalizado\n\n");	
	ft_free_arr(argv);
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