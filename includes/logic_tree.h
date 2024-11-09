/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 15:13:19 by marsoare         ###   ########.fr       */
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

//build_ltree.c
void	*build_ltree(t_shell *shell, t_list *token_list);
void	*insert_lnode(t_shell *shell, void *lnode, t_list *token_lst);
void	*create_subtree(t_shell *shell, t_list *token_lst);
void	*create_andif(t_shell *shell, void *left, void *right);

//ltree_print.c
void	*ltree_print(void *root, int space);

#endif
