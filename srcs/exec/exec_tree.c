/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:37:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
void	exec_tree(t_shell *shell, void *root)
{
	char	*cmd_path = find_cmd_path(shell->path, ((t_exec *)root)->command);
	printf("cmd_path: %s\n", cmd_path);
	if (execve(cmd_path, ((t_exec *)root)->argv, NULL) == -1)
	{
		free_shell(shell);
		exit(1);
	}
}
*/

void	exec_tree(t_shell *shell, void *root)
{
	if (((t_node *)root)->type == N_PIPE)
		exec_pipe(shell, root);
	else if (((t_node *)root)->type == N_EXEC)
		exec_node(shell, root);
}

void	exec_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	if (fork() == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exec_tree(shell, pipe_node->left);
		exit(0);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		exec_tree(shell, pipe_node->right);
		wait(NULL);
	}
}

void	exec_node(t_shell *shell, t_exec *exec_node)
{
	char	*cmd_path;

	cmd_path = find_cmd_path(shell->path, exec_node->command);
	if (!cmd_path)
	{
		fprintf(stderr, "Command not found: %s\n", exec_node->command);
		exit(1);
	}
	if (execve(cmd_path, exec_node->argv, NULL) == -1)
	{
		perror("execve failed");
		free_shell(shell);
		exit(1);
	}
}
