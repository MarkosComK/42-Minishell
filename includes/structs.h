/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:30:38 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 17:11:09 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <libft.h>
# include <limits.h>

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
	char		*cwd;
	int			exit_code;
	int			fd;
}				t_shell;

#endif
