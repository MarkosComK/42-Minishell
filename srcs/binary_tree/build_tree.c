/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 16:42:30 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_tree(t_shell *shell, t_list *token_list)
{
	t_list	*tmp;
	void	*root;

	tmp = token_list;
	root = NULL;
	while (tmp)
	{
		root = insert_node(shell, root, tmp);
		if (((t_token *)tmp->content)->type != PIPE)
		{
			while (tmp && ((t_token *)tmp->content)->type != PIPE)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tmp->next;
			while (tmp && ((t_token *)tmp->content)->type != PIPE)
			{
				tmp = tmp->next;
			}
		}
	}
	return (root);
}

void	*insert_node(t_shell *shell, void *node, t_list *token_lst)
{
	t_pipe	*pipe;

	if (!node)
		return (create_exec(shell, token_lst));
	pipe = create_pipe(shell, node, create_exec(shell, token_lst->next));
	return (pipe);
}

void	*create_exec(t_shell *shell, t_list *token_lst)
{
	t_exec	*node;

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
	if (((t_token *)token_lst->content)->type == INFILE)
		node->infiles = get_infiles(shell, &token_lst);
	if (token_lst && ((t_token *)token_lst->content)->type == OUTFILE)
		node->outfiles = get_outfiles(shell, &token_lst);
	if (((t_token *)token_lst))
	{
		node->command = ((t_token *)token_lst->content)->value;
		node->argv = get_argv(shell, token_lst);
		if (ft_strcmp(node->argv[0], node->command) == 0)
			node->argv = get_colors(shell, node->argv);
		token_lst = (token_lst)->next;
	}
	return (node);
}

void	*create_pipe(t_shell *shell, t_exec *left, t_exec *right)
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
