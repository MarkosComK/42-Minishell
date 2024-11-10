/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 11:18:24 by marsoare         ###   ########.fr       */
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

//ltree_print.c
void	*ltree_print(void *root, int space);
void	ltree_free(void *root);

#endif
