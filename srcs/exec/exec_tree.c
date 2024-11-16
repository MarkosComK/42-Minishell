/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 12:51:41 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	last_process(int value)
{
	static int	code = 0;

	if (value == -1)
		return (code);
	code = value;
	return (code);
}

void	lexec_tree(t_shell *shell, void *root)
{
	t_node	*node;

	if (!root)
		return ;
	node = (t_node *)root;
	if (node->type == N_ANDIF)
	{
		lexec_tree(shell, ((t_andif *)root)->left);
		last_process(exit_code(-1));
		if (last_process(-1) == 0)
			lexec_tree(shell, ((t_andif *)root)->right);
		last_process(exit_code(-1));
	}
	else if (node->type == N_OR)
	{
		lexec_tree(shell, ((t_or *)root)->left);
		last_process(exit_code(-1));
		if (last_process(-1) != 0)
			lexec_tree(shell, ((t_or *)root)->right);
	}
	else if (node->type == N_PIPE)
		exec_processes(shell, root);
	else if (node->type == N_EXEC)
		exec_processes(shell, root);
	return ;
}

void	exec_tree(t_shell *shell, void *root)
{
	if (((t_node *)root)->type == N_PIPE)
		exec_pipe(shell, root);
	else if (((t_node *)root)->type == N_EXEC)
		exec_node(shell, root);
	else if (((t_node *)root)->type == N_ANDIF)
	{
		lexec_tree(shell, root);
		free_env_lst(shell->envp);
		free_shell(shell);
	}
	else if (((t_node *)root)->type == N_OR)
	{
		lexec_tree(shell, root);
		free_env_lst(shell->envp);
		free_shell(shell);
	}
}

void	exec_pipe(t_shell *shell, t_pipe *pipe_node)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	status = 0;
	pid1 = fork();
	if (pid1 == 0)
		handle_pid1(shell, pipefd, pipe_node);
	pid2 = fork();
	if (pid2 == 0)
		handle_pid2(shell, pipefd, pipe_node);
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit_status(status);
	free_env_lst(shell->envp);
	free_shell(shell);
	exit(exit_code(-1));
}

//muitas coisas na vida sao estranhas, mas nada vencera as validacoes
//pra minha menssagem de erro.
void	*exec_node(t_shell *shell, t_exec *exec_node)
{
	int		ret;

	check_files_order(shell, exec_node);
	exec_node->argv = expand_argv(shell, exec_node->argv);
	if (exec_node->command && is_builtin(exec_node->command))
	{
		ret = exec_builtin(shell, exec_node);
		return (exec_free(shell, exec_node), exit(ret), NULL);
	}
	set_fork1_signal();
	shell->cmd_path = find_cmd_path(shell, shell->path, exec_node->argv[0]);
	printf("cmd_path:%s\n", shell->cmd_path);
	printf("exec_node[0]:%s\n", exec_node->argv[0]);
	if (exec_node->argv)
		is_directory(shell, exec_node->argv);
	if (execve(shell->cmd_path, exec_node->argv, shell->envp_arr) < 0)
	{
		free_env_lst(shell->envp);
		if (exec_node->argv && exec_node->argv[0])
		{
			free_expand(exec_node->argv);
			exec_failure(shell, shell->cmd_path);
		}
		free_shell(shell);
		exit(0);
	}
	return (free_expand(exec_node->argv), NULL);
}
