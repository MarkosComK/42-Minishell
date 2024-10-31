/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:49:40 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/28 21:22:09 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <binary_tree.h>
# include <structs.h>

typedef struct s_env
{
	int		key;
	char	*value;
	char	*content;
}				t_env;

// EXEC
int		exec_builtin(t_shell *shell, t_exec *exec_node);
int		is_builtin(const char *command);

// ECHO
int		ft_echo(t_exec *exec_node);
int		echo_flag_n(char *arg);
void	echo_output(char **args, int idx, int newline);

//ENV
char	**env_arr(t_shell *shell);
t_list	*path_list(t_shell *shell, char **envp);
int		get_path(t_shell *shell, t_list **path_list, char *path, int i);
void	print_env_lst(t_list *lst);

//env_utils.c
t_list	*env_list(t_shell *shell, char **envp);
t_env	*create_node_env(t_shell *shell, char **envp, int index);
char	*env_value(t_shell *shell, char *env);
int		val_size(char *env);

// PWD
void	ft_pwd(void);
int		check_pwd(t_exec *exec_node);

//UTILS
void	ft_putendl_fd_pt(char *s, int fd);

void	test_echo(void);

#endif
