/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:53:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 12:56:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <structs.h>

typedef enum e_node_type
{
	N_PIPE,
	N_EXEC,
}				t_node_type;

typedef struct s_node
{
	t_node_type	type;
}				t_node;

typedef struct s_pipe
{
	t_node			type;
	struct s_exec	*left;
	struct s_exec	*right;
}				t_pipe;

typedef struct s_exec
{
	t_node		type;
	char		*command;
}				t_exec;

//bst_free.c
void	free_bst(void *root);
void	free_pipe_children(t_pipe *pipe);
void	free_exec(t_exec *node);
//bst_print.c
void	*print_bst(void *root, int space);
void	print_pipe_children(t_pipe *pipe, int space);
void	print_bst_pipe(t_pipe *node, int space);
void	print_bst_exec(t_exec *node, int space);
//build_tree.c
void	*build_tree(t_list *token_list);
void	*insert_node(void *node, t_list *token_lst);
void	*create_pipe(t_exec *left, t_exec *right);
void	*create_exec(t_list *token_lst);

#endif
