/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:21:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 22:45:47 by marsoare         ###   ########.fr       */
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
	argc = count_args(current);
	argv = malloc((argc + 1) * sizeof(char *));
	if (!argv)
		exit_failure(shell, "get_argv");
	current = token_lst;
	while (current && ((t_token *)current->content)->type != PIPE && i < argc)
	{
		if (current && ((t_token *)current->content)->type == WORD)
		{
			current = check_word(&current, argv, &i);
			continue ;
		}
		current = current->next->next;
	}
	return (argv[argc] = NULL, argv);
}

t_list	*get_infiles(t_shell *shell, t_list *token_lst, t_list **infiles)
{
	t_list	*current;
	char	*content;

	current = token_lst;
	while (current && ((t_token *)current->content)->type != PIPE)
	{
		if (current && ((t_token *)current->content)->type == INFILE)
		{
			content = ft_strdup(((t_token *)current->next->content)->value);
			if (!content)
				exit_failure(shell, "get_infiles");
			ft_lstadd_back(infiles, ft_lstnew(content));
			current = current->next->next;
			continue ;
		}
		current = current->next;
	}
	return (current);
}

t_list	*get_outfiles(t_shell *shell, t_list *token_lst, t_list **outfiles)
{
	t_list	*current;
	t_outf	*content;

	current = token_lst;
	while (current && ((t_token *)current->content)->type != PIPE)
	{
		if (current && (((t_token *)current->content)->type == OUTFILE
				|| ((t_token *)current->content)->type == APPEND))
		{
			content = malloc(sizeof(t_outf));
			if (!content)
				exit_failure(shell, "get_outfiles");
			if (((t_token *)current->content)->type == APPEND)
				content->type = APP;
			else
				content->type = ADD;
			content->name = ft_strdup(((t_token *)
						current->next->content)->value);
			ft_lstadd_back(outfiles, ft_lstnew(content));
			current = current->next->next;
			continue ;
		}
		current = current->next;
	}
	return (current);
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

t_list	*check_w_args(t_list *tkn_lst, int *args)
{
	if (tkn_lst && ((t_token *)tkn_lst->content)->type == WORD)
	{
		if (((t_token *)tkn_lst->content)->state == EXPAND
			&& ft_strlen(((t_token *)tkn_lst->content)->value) == 0)
		{
			return (tkn_lst->next);
		}
		(*args)++;
	}
	return (tkn_lst->next);
}

int	count_args(t_list *tkn_lst)
{
	int		args;

	args = 0;
	while (tkn_lst && ((t_token *)tkn_lst->content)->type != PIPE)
	{
		if (tkn_lst && ((t_token *)tkn_lst->content)->type == INFILE)
		{
			tkn_lst = tkn_lst->next->next;
			continue ;
		}
		if (tkn_lst && (((t_token *)tkn_lst->content)->type == OUTFILE
				|| ((t_token *)tkn_lst->content)->type == APPEND))
		{
			tkn_lst = tkn_lst->next->next;
			continue ;
		}
		tkn_lst = check_w_args(tkn_lst, &args);
	}
	return (args);
}
