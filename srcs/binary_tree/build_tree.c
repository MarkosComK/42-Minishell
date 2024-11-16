/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 11:04:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_tree(t_shell *shell, t_list *token_list)
{
	t_list	*tmp;
	void	*root;

	tmp = token_list;
	root = NULL;
	while (check_token(tmp))
	{
		root = insert_node(shell, root, tmp);
		if (((t_token *)tmp->content)->type != PIPE)
		{
			tmp = skip_if(tmp);
		}
		else
		{
			tmp = skip_else(tmp);
		}
	}
	return (root);
}

void	*insert_node(t_shell *shell, void *node, t_list *token_lst)
{
	t_pipe	*pipe;
	t_list	*new;

	if (!node)
		return (create_exec(shell, token_lst));
	if (is_parenthesis(token_lst->next))
	{
		new = NULL;
		new = new_sublist(token_lst->next);
		pipe = create_pipe(shell, node, build_ltree(shell, new));
		clean_sublist(new);
	}
	else
		pipe = create_pipe(shell, node, create_exec(shell, token_lst->next));
	return (pipe);
}

void	*create_exec(t_shell *shell, t_list *token_lst)
{
	t_exec	*node;
	t_list	*current;

	if (!token_lst)
		return (NULL);
	node = (t_exec *)malloc(sizeof(t_exec));
	if (!node)
		exit_failure(shell, "crete_exec");
	node->type.type = N_EXEC;
	node->infiles = NULL;
	node->command = NULL;
	node->argv = NULL;
	node->outfiles = NULL;
	get_infiles(shell, token_lst, &node->infiles);
	get_outfiles(shell, token_lst, &node->outfiles);
	current = get_name(token_lst);
	if (current)
	{
		node->command = ((t_token *)current->content)->value;
		node->argv = get_argv(shell, token_lst);
		if (ft_strcmp(node->argv[0], "ls") == 0
			|| ft_strcmp(node->argv[0], "grep") == 0)
			node->argv = get_colors(shell, node->argv);
	}
	return (node);
}

void	*create_pipe(t_shell *shell, void *left, void *right)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	if (!node)
		exit_failure(shell, "crete_exec");
	node->type.type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}

t_list	*get_name(t_list *tkn_lst)
{
	t_list	*word;

	word = NULL;
	while (tkn_lst && (((t_token *)tkn_lst->content)->type != PIPE))
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
		if (tkn_lst && ((t_token *)tkn_lst->content)->type == WORD
			&& ((t_token *)tkn_lst->content)->state != EXPAND)
			return (tkn_lst);
		tkn_lst = tkn_lst->next;
		if (tkn_lst && ((t_token *)tkn_lst->content)->type == AND_IF)
			break ;
	}
	return (word);
}
