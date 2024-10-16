/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:53:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/16 11:21:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE
# define BINARY_TREE

#include <structs.h>

typedef enum	e_node_type
{
	N_PIPE,
	N_EXEC,
}				t_node_type;

typedef struct	s_node
{
	t_node_type	type;
}				t_node;

typedef struct	s_pipe
{
	t_node			type;
	struct s_exec	*left;
	struct s_exec	*right;
}				t_pipe;

typedef struct	s_exec
{
	t_node		type;
	char		*command;
}				t_exec;

void	*build_tree(t_list *token_list);
void	*print_bst(void *root, int space);

#endif
