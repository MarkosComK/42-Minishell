/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:49:40 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/28 21:03:55 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <binary_tree.h>
# include <structs.h>

// EXEC
int		exec_builtin(t_exec *exec_node);
int		is_builtin(const char *command);

// ECHO
int		ft_echo(t_exec *exec_node);
int		echo_flag_n(char *arg);
void	echo_output(char **args, int idx, int newline);
// PWD
void	ft_pwd(void);
int		check_pwd(t_exec *exec_node);

//UTILS
void	ft_putendl_fd_pt(char *s, int fd);

void	test_echo(void);

#endif