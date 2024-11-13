/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:12:02 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 14:12:02 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H

# include <dirent.h>

typedef struct dirent t_dirent;

typedef struct s_pattern
{
    char *str;
    struct s_pattern *next;
} t_pattern;

//wildcard.c
char    **process_wildcard(char **args);
char    **expand_wildcard(char *token);

//wildcard_utils.c
void    ft_free_arr(char **arr);
void    ft_free_expansion(char ***expansion, int count);
int     ft_arrlen(char **arr);