/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:12:02 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 14:09:37 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARDS_H
# define WILDCARDS_H

# include <binary_tree.h>
# include <dirent.h>
# include <structs.h>

typedef struct dirent	t_dirent;

// wildcard.c
char					**process_wildcards(char **args);
char					**expand_wildcard(char *token);
char					**merge_expansions(char ***expanded, int count);
int						match_pattern(char *pattern, char *str);
char					**pattern_to_arr(t_list *matches, char *token);

// wildcard_utils.c
int						ft_arrlen(char **arr);
t_list					*pattern_new(char *str);
void					ft_free_arr(char **arr);
void					ft_free_exp(char ***expansion, int count);
char					**get_result(char ***exp, int count, int total);

// wildcard_utils2.c
char					***get_expand(char **argv, int size);
t_list					*generate_matches(t_dirent *entry, char *token,
							t_list *matches);
char					**validate_matches(char *token);

// wildcard_validations.c
void					check_wildcards(t_shell *shell, t_exec *exec_node);
t_list					*get_matches(char *token);
int						has_wildcard(char **argv);
int						is_valid_wildcard(char *arg);

#endif
