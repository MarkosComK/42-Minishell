/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:21:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/18 16:28:29 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_argv(t_list *token_lst)
{
	t_list	*current;
    int		argc;
    char	**argv;

	current = token_lst;
	argc = 0;
	argv = NULL;
	while (current && ft_strcmp(((t_token *)current->content)->value, "|") != 0)
	{
		argc++;
		current = current->next;
	}
	argv = malloc((argc + 1) * sizeof(char *));
	current = token_lst;
	for (int i = 0; i < argc; i++)
	{
		argv[i] = ((t_token *)current->content)->value;
		current = current->next;
	}
	argv[argc] = NULL;
	return (argv);
}
