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

char	**get_argv(t_shell *shell, t_list **token_lst)
{
	t_list	*current;
	int		argc;
	char	**argv;
	int		i;

	current = *token_lst;
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
	current = *token_lst;
	while (i < argc)
	{
		argv[i] = ((t_token *)current->content)->value;
		current = current->next;
		*token_lst = (*token_lst)->next;
		i++;
	}
	return (argv[argc] = NULL, argv);
}

t_list	*get_infiles(t_shell *shell, t_list **token_lst)
{
	t_list	*infiles;
	t_list	*current;
	char	*content;

	infiles = NULL;
	current = *token_lst;
	while (current && ((t_token *)current->content)->type == INFILE)
	{
		content = ft_strdup(((t_token *)current->next->content)->value);
		ft_lstadd_back(&infiles, ft_lstnew(content));
		if (!infiles)
			exit_failure(shell, "get_infiles");
		current = current->next->next;
		*token_lst = (*token_lst)->next->next;
	}
	return (infiles);
}

t_list	*get_outfiles(t_shell *shell, t_list **token_lst)
{
	t_list	*outfiles;
	t_list	*current;
	t_outf	*content;

	outfiles = NULL;
	current = *token_lst;
	while (current && (((t_token *)current->content)->type == OUTFILE
			|| ((t_token *)current->content)->type == APPEND))
	{
		content = malloc(sizeof(t_outf));
		if (((t_token *)current->content)->type == APPEND)
			content->type = APP;
		else
			content->type = ADD;
		content->name = ft_strdup(((t_token *)current->next->content)->value);
		ft_lstadd_back(&outfiles, ft_lstnew(content));
		if (!outfiles)
			exit_failure(shell, "get_infiles");
		current = current->next->next;
		*token_lst = (*token_lst)->next->next;
	}
	return (outfiles);
}

char	**get_colors(t_shell *shell, char **argv)
{
	char	**colors;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	colors = malloc(sizeof(char *) * (i + 2));
	if (!colors)
		exit_failure(shell, "get_colors");
	ft_memcpy(colors, argv, sizeof(char *) * i);
	colors[i] = "--color=auto";
	colors[i + 1] = NULL;
	free(argv);
	return (colors);
}
