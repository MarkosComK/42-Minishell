/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:49:40 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/03 15:30:30 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <binary_tree.h>
# include <structs.h>

typedef struct s_env
{
	char	*value;
	char	*content;
}				t_env;

//builtins_utils.c
int		is_builtin(const char *command);
int		exec_builtin(t_shell *shell, t_exec *exec_node);
int		exec_parent_builtin(t_shell *shell, t_exec *exec_node);
int		is_parent_builtin(t_exec *exec_node);	
int		handle_builtins(t_shell *shell, t_exec *exec_node);

//echo.c
int		ft_echo(t_exec *exec_node);
int		echo_flag_n(char *arg);
void	echo_output(char **args, int idx, int newline);

//env.c
char	**env_arr(t_shell *shell);
t_list	*path_list(t_shell *shell, char **envp);
int		get_path(t_shell *shell, t_list **path_list, char *path, int i);
void	print_env_lst(t_list *lst);

//env_utils.c
t_list	*env_list(t_shell *shell, char **envp);
t_env	*create_node_env(t_shell *shell, char **envp);
char	*get_value(t_shell *shell, char *env);
char	*get_content(t_shell *shell, char *env);

//env_utils_sizes.c
int		content_size(char *env);
int		val_size(char *env);

//exit.c ~ empty

//export.c ~ empty
void ft_export(t_shell *shell, char **args);
void    export_var(t_shell *shell, const char *arg);
void upt_env_var(t_shell *shell, char *value, char *content);
char	*create_value(t_shell *shell, const char *arg, char *equal);

//pwd.c
void	ft_pwd(void);
int		check_pwd(t_exec *exec_node);

//unset.c ~ empty

#endif
