/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:33:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/09 17:44:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	shell_input(t_shell *shell)
{
	char	*prompt;
	char	cwd[PATH_MAX];
	char	*tmp;

	getcwd(cwd, sizeof(cwd));
	prompt = "\001" B_RED "\002Minishell\001" DEFAULT "\002";
	tmp = ft_strjoin(prompt, cwd);
	shell->cwd = ft_strjoin(tmp, "\001"B_RED"\002 → \001"DEFAULT"\002");
	free(tmp);
}

void	exec_processes(t_shell *shell, void *root)
{
	t_exec	*exec;
	int		status;

	status = 0;
	exec = NULL;
	set_main_signals();
	handle_heredoc(shell, root);
	if (((t_node *)root)->type == N_EXEC )
	{
		exec = (t_exec *)root;
		if (is_parent_builtin(exec))
			exec_parent_builtin(shell, exec);
		else
		{
			if (fork() == 0)
				exec_tree(shell, root);
			waitpid(-1, &status, 0);
			exit_status(status);
			return ;
		}
	}
	if (fork() == 0)
		exec_tree(shell, root);
	waitpid(-1, &status, 0);
	exit_status(status);
}

int	is_env_empty(t_shell *shell)
{
	return (shell->envp == NULL || ft_lstsize(shell->envp) == 0);
}

void	finish_shell(t_shell *shell)
{
	shell->envp_arr = NULL;
	shell->path = NULL;
	shell->token_lst = NULL;
	shell->input = NULL;
	shell->trim_input = NULL;
	shell->root = NULL;
	shell->cmd_path = NULL;
	shell->cwd = NULL;
	shell->exit_code = 0;
}

void	start_shell(t_shell *shell)
{
	shell->envp_arr = NULL;
	shell->path = NULL;
	shell->token_lst = NULL;
	shell->input = NULL;
	shell->trim_input = NULL;
	shell->root = NULL;
	shell->cmd_path = NULL;
	shell->cwd = NULL;
	shell->exit_code = 0;
}
