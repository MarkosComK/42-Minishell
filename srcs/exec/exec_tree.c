/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:43:04 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 15:59:48 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
	pid1 = fork();
	if (pid1 == 0)
		handle_pid1(shell, pipefd, pipe_node);
	pid2 = fork();
	if (pid2 == 0)
		handle_pid2(shell, pipefd, pipe_node);
	close(pipefd[0]);
	close(pipefd[1]);
	status = 0;
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	exit_status(status);
	free_env_lst(shell->envp);
	free_shell(shell);
	exit(exit_code(-1));
}

//muitas coisas na vida sao estranhas, mas nada vencera as validacoes
//pra minha menssagem de erro.
void	exec_node(t_shell *shell, t_exec *exec_node)
{
	int		ret;

	handle_infiles(shell, exec_node);
	handle_outfiles(shell, exec_node);
	if (exec_node->command && is_builtin(exec_node->command))
	{
		ret = exec_builtin(shell, exec_node);
		free_env_lst(shell->envp);
		free_shell(shell);
		exit(ret);
		return ;
	}
	set_fork1_signal();
	shell->cmd_path = find_cmd_path(shell, shell->path, exec_node->command);
	if (exec_node->argv)
		is_directory(shell, exec_node->argv[0]);
	if (execve(shell->cmd_path, exec_node->argv, shell->envp_arr) < 0)
	{
		free_env_lst(shell->envp);
		exec_failure(shell, shell->cmd_path, exec_node->argv);
	}
}
