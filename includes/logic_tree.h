/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:28:11 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 12:33:20 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_TREE_H
# define LOGIC_TREE_H

typedef struct s_andif
{
	void	*root;
	void	*left;
	void	*right;
}				t_andif;

//build_ltree.c
void	*build_ltree(t_shell *shell, t_list *token_list);
void	*insert_lnode(t_shell *shell, void *lnode, t_list *token_lst);
void	*create_subtree(t_shell *shell, t_list *token_lst);

#endif
