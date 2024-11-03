/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:53:24 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:09:51 by marsoare         ###   ########.fr       */
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

typedef enum e_outf_t
{
	APP,
	ADD,
}				t_outf_t;

typedef struct s_outf
{
	t_outf_t	type;
	char		*name;
}				t_outf;

typedef struct s_exec
{
	t_node		type;
	char		*command;
	char		**argv;
	t_list		*infiles;
	t_list		*outfiles;
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

//bst_print_utils.c
void	print_bst_exec(t_exec *node, int space);
void	print_outfiles(t_list *outfiles, int space);
void	print_exec(char **argv, int space);
void	print_infiles(t_list *infiles, int space);

//build_tree.c
void	*build_tree(t_shell *shell, t_list *token_list);
void	*insert_node(t_shell *shell, void *node, t_list *token_lst);
void	*create_pipe(t_shell *shell, t_exec *left, t_exec *right);
void	*create_exec(t_shell *shell, t_list *token_lst);
t_list	*get_name(t_list *tkn_lst);

//build_tree_utils.c
char	**get_argv(t_shell *shell, t_list *token_lst);
t_list	*get_infiles(t_shell *shell, t_list *token_lst, t_list **infiles);
t_list	*get_outfiles(t_shell *shell, t_list *token_lst, t_list **outfiles);
char	**get_colors(t_shell *shell, char **argv);
int		count_args(t_list *tkn_lst);

#endif
