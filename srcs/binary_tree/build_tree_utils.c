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

char	**get_argv(t_shell *shell, t_list *token_lst)
{
	t_list	*current;
	int		argc;
	char	**argv;
	int		i;

	current = token_lst;
	argc = 0;
	i = 0;
	while (current && ((t_token *)current->content)->type == WORD)
	{
		argc++;
		current = current->next;
	}
	argv = malloc((argc + 1) * sizeof(char *));
	if (!argv)
		exit_failure(shell, "get_argv");
	current = token_lst;
	while (i < argc)
	{
		argv[i] = ((t_token *)current->content)->value;
		current = current->next;
		i++;
	}
	argv[argc] = NULL;
	return (argv);
}

char	**get_infiles(t_shell *shell, t_list **token_lst)
{
	char	**infiles;
	t_list	*current;
	int		total;

	current = *token_lst;
	total = 0;
	while (current && ((t_token *)current->content)->type == INFILE)
	{
		total++;
		current = current->next->next;
	}
	infiles = malloc(sizeof(char *) * (total + 1));
	if (!infiles)
		exit_failure(shell, "get_infiles");
	total = 0;
	current = *token_lst;
	while (current && ((t_token *)current->content)->type == INFILE)
	{
		infiles[total] = ft_strdup(((t_token *)current->next->content)->value);
		if (!infiles[total++])
			exit_failure(shell, "get_infiles");
		current = current->next->next;
		*token_lst = (*token_lst)->next->next;
	}
	return (infiles[total] = NULL, infiles);
}

char	**get_outfiles(t_shell *shell, t_list **token_lst)
{
	char	**infiles;
	t_list	*current;
	int		total;

	current = *token_lst;
	total = 0;
	while (current && ((t_token *)current->content)->type == OUTFILE)
	{
		total++;
		current = current->next->next;
	}
	infiles = malloc(sizeof(char *) * (total + 1));
	if (!infiles)
		exit_failure(shell, "get_infiles");
	total = 0;
	current = *token_lst;
	while (current && ((t_token *)current->content)->type == OUTFILE)
	{
		infiles[total] = ft_strdup(((t_token *)current->next->content)->value);
		if (!infiles[total++])
			exit_failure(shell, "get_infiles");
		current = current->next->next;
		*token_lst = (*token_lst)->next->next;
	}
	return (infiles[total] = NULL, infiles);
}
