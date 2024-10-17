/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 13:13:15 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*build_tree(t_list *token_list)
{
	t_list	*tmp;
	void	*root;
	//t_node	*node;

	tmp = token_list;
	root = NULL;
	while (tmp && tmp->next)
	{
		//print_token_lst(tmp);
		root = insert_node(root, tmp);
		if (((t_token *)tmp->content)->type == WORD)
		{
			while (tmp && ((t_token *)tmp->content)->type == WORD)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			tmp = tmp->next;
			while (tmp && ((t_token *)tmp->content)->type == WORD)
			{
				tmp = tmp->next;
			}
		}
	}
	return (root);
}

void	*insert_node(void *node, t_list *token_lst)
{
	t_pipe	*pipe;

	if (!node)
		return (create_exec(token_lst));
	pipe = create_pipe(node, create_exec(token_lst->next));
	return (pipe);
}

void	*create_exec(t_list *token_lst)
{
	t_exec	*node;
    int argc = 0;
    char **argv = NULL;

	if (!token_lst)
		return (NULL);
	node = (t_exec *)malloc(sizeof(t_exec));
	node->type.type = N_EXEC;
	node->command = ((t_token *)token_lst->content)->value;
	
	// Count the number of arguments until we hit a pipe
	t_list *current = token_lst;
	while (current && ft_strcmp(((t_token *)current->content)->value, "|") != 0)
	{
		argc++;
		current = current->next;
	}
	argv = malloc((argc + 1) * sizeof(char *));
	if (!argv)
	{
		free(node);
		return NULL;
	}
	current = token_lst;
	for (int i = 0; i < argc; i++)
	{
		argv[i] = ((t_token *)current->content)->value;
		current = current->next;
	}
	argv[argc] = NULL;
	node->argv = argv;
	return (node);
}

void	*create_pipe(t_exec *left, t_exec *right)
{
	t_pipe	*node;

	node = (t_pipe *)malloc(sizeof(t_pipe));
	node->type.type = N_PIPE;
	node->left = left;
	node->right = right;
	return (node);
}
