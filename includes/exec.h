/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:42:37 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:45 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <structs.h>

//exec_expand.c
char	**expand_argv(t_shell *shell, char **argv);
void	free_expand(char **argv);
char	*f(t_shell *shell, char *input);

//exec_tree.c
void	lexec_tree(t_shell *shell, void *root);
void	exec_tree(t_shell *shell, void *root);
void	exec_pipe(t_shell *shell, t_pipe *pipe_node);
void	*exec_node(t_shell *shell, t_exec *exec_node);

//exec_utils.c
char	*find_cmd_path(t_shell *shell, t_list *path_list, char *command);
void	exec_free(t_shell *shell, t_exec *exec_node);

//pids_utils.c
void	handle_pid1(t_shell *shell, int pipefd[], t_pipe *pipe_node);
void	handle_pid2(t_shell *shell, int pipefd[], t_pipe *pipe_node);

//redirects.c
void	check_files_order(t_shell *shell, t_exec *exec_node);
void	handle_infiles(t_shell *shell, t_list *infiles, int pos);
void	handle_outfiles(t_shell *s, t_list *outfiles, int pos);

//redirects_utils.c
void	dup_file2(char *name, int fd);
void	dup_file(char *name, int fd);

#endif
