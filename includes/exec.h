/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:42:37 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 17:33:13 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <structs.h>

//exec_tree
void	lexec_tree(t_shell *shell, void *root);
void	exec_tree(t_shell *shell, void *root);
void	exec_pipe(t_shell *shell, t_pipe *pipe_node);
void	exec_node(t_shell *shell, t_exec *exec_node);

//exec_utils
char	*find_cmd_path(t_shell *shell, t_list *path_list, char *command);

//pids_utils
void	handle_pid1(t_shell *shell, int pipefd[], t_pipe *pipe_node);
void	handle_pid2(t_shell *shell, int pipefd[], t_pipe *pipe_node);

//redirects
void	check_files_order(t_shell *shell, t_exec *exec_node);
void	handle_infiles(t_shell *shell, t_exec *exec_node, int pos);
void	handle_outfiles(t_shell *shell, t_exec *exec_node, int pos);

#endif
