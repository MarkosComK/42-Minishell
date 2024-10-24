/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 03:43:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 03:51:40 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handle_pid1(t_shell *shell, int pipefd[], t_pipe *pipe_node)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	exec_tree(shell, pipe_node->left);
	exit(0);
}

void	handle_pid2(t_shell *shell, int pipefd[], t_pipe *pipe_node)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	exec_tree(shell, pipe_node->right);
	exit(0);
}
