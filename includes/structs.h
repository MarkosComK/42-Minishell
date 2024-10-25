/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:30:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 14:48:50 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>

typedef struct s_shell
{
	t_list		*envp;
	char		**envp_arr;
	t_list		*path; //path_list
	t_list		*token_lst;
	char		*input;
	char		*trim_input;
	void		*root; //binary tree root
	char		*cmd_path;
}				t_shell;

#endif
