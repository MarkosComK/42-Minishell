/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:53:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 20:11:17 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE
# define BINARY_TREE

typedef enum	e_node_type
{
	N_PIPE,
	N_EXEC,
}				t_node_type;

typedef struct	s_pipe
{
	t_node_type		type;
	struct s_exec	*left;
	struct s_exec	*right;
}				t_pipe;

typedef struct	s_exec
{
	t_node_type	type;
	char		*command;
}				t_exec;

#endif
