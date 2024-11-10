/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:21:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 10:44:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**get_argv(t_shell *shell, t_list *t_lst)
{
	int		argc;
	char	**argv;
	int		i;

	argc = 0;
	i = 0;
	argc = count_args(t_lst);
	argv = ft_calloc((argc + 1), sizeof(char *));
	if (!argv)
		exit_failure(shell, "get_argv");
	while (t_lst && ((t_token *)t_lst->content)->type != PIPE && i < argc)
	{
		if (t_lst && ((t_token *)t_lst->content)->type == WORD)
		{
			t_lst = check_word(&t_lst, argv, &i);
			continue ;
		}
		if (check_token(t_lst->next))
			break ;
		t_lst = t_lst->next->next;
	}
	return (argv[argc] = NULL, argv);
}

t_list	*get_infiles(t_shell *shell, t_list *tkn_lst, t_list **infiles)
{
	t_inf	*content;

	while (tkn_lst && ((t_token *)tkn_lst->content)->type != PIPE)
	{
		if (tkn_lst && (((t_token *)tkn_lst->content)->type == INFILE
				|| ((t_token *)tkn_lst->content)->type == HEREDOC))
		{
			content = ft_calloc(sizeof(t_inf), 1);
			if (!content)
				exit_failure(shell, "get_outfiles");
			if (((t_token *)tkn_lst->content)->type == INFILE)
				content->type = INF;
			else
				content->type = HERE;
			content->eof = ft_strdup(((t_token *)
						tkn_lst->next->content)->value);
			ft_lstadd_back(infiles, ft_lstnew(content));
			tkn_lst = tkn_lst->next->next;
			continue ;
		}
		tkn_lst = tkn_lst->next;
		if (check_token(tkn_lst))
			break ;
	}
	return (tkn_lst);
}

t_list	*get_outfiles(t_shell *shell, t_list *tkn_lst, t_list **outfiles)
{
	t_outf	*content;

	while (tkn_lst && ((t_token *)tkn_lst->content)->type != PIPE)
	{
		if (tkn_lst && (((t_token *)tkn_lst->content)->type == OUTFILE
				|| ((t_token *)tkn_lst->content)->type == APPEND))
		{
			content = ft_calloc(1, sizeof(t_outf));
			if (!content)
				exit_failure(shell, "get_outfiles");
			if (((t_token *)tkn_lst->content)->type == APPEND)
				content->type = APP;
			else
				content->type = ADD;
			content->name = ft_strdup(((t_token *)
						tkn_lst->next->content)->value);
			ft_lstadd_back(outfiles, ft_lstnew(content));
			tkn_lst = tkn_lst->next->next;
			continue ;
		}
		tkn_lst = tkn_lst->next;
		if (check_token(tkn_lst))
			break ;
	}
	return (tkn_lst);
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

int	count_args(t_list *tkn_lst)
{
	int		args;

	args = 0;
	while (tkn_lst && ((t_token *)tkn_lst->content)->type != PIPE)
	{
		if (tkn_lst && (((t_token *)tkn_lst->content)->type == INFILE
				|| ((t_token *)tkn_lst->content)->type == HEREDOC))
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
		if (check_token(tkn_lst))
			break ;
	}
	return (args);
}
