/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:42:37 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:36:23 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <structs.h>

void	exec_tree(t_shell *shell, void *root);
void	exec_pipe(t_shell *shell, t_pipe *pipe_node);
void	exec_node(t_shell *shell, t_exec *exec_node);

#endif
