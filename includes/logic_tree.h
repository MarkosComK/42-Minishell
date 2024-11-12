/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 13:44:32 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_TREE_H
# define LOGIC_TREE_H

typedef struct s_andif
{
	t_node	type;
	void	*left;
	void	*right;
}				t_andif;

typedef struct s_or
{
	t_node	type;
	void	*left;
	void	*right;
}				t_or;

//build_ltree.c
void	*build_ltree(t_shell *shell, t_list *token_list);
void	*insert_lnode(t_shell *shell, void *lnode, t_list *token_lst);
void	*create_subtree(t_shell *shell, t_list *token_lst);
void	*create_and(t_shell *shell, void *left, void *right);
void	*create_or(t_shell *shell, void *left, void *right);

//build_ltree_utils.c
int		check_token(t_list *node);

//ltree_parenthesis.c
t_list	*new_sublist(t_list *t_lst);
void	clean_sublist(t_list *new);
void	*get_andif_subnode(t_shell *shell, void *l_node, t_list *t_lst);
void	*get_or_subnode(t_shell *shell, void *l_node, t_list *t_lst);

//ltree_print.c
void	*ltree_print(void *root, int space);
void	ltree_free(void *root);

#endif
