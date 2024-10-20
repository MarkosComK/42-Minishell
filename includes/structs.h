/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:30:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/29 16:32:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>

typedef struct s_shell
{
	t_list		**path; //env_list
	t_list		*token_lst;
	char		*input;
	char		*trim_input;
	void		*root; //binary tree root
}				t_shell;

#endif
