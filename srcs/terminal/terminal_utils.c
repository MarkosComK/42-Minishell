/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:33:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/10 14:12:54 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	shell_input(t_shell *shell)
{
	char	*prompt;
	char	*cwd;
	char	*tmp;
	char	*tmp2;
	char	*code;

	code = ft_itoa(exit_code(-1));
	cwd = getcwd(NULL, 0);
	prompt = ESC_START PROMPT ESC_RESET;
	tmp = ft_strjoin(prompt, code);
	free(code);
	if (!tmp)
		exit_failure(shell, "shell_input");
	tmp2 = ft_strjoin(tmp, ESC_CODE);
	free(tmp);
	if (!tmp2)
		exit_failure(shell, "shell_input");
	tmp = ft_strjoin(tmp2, cwd);
	free(tmp2);
	if (!tmp)
		exit_failure(shell, "shell_input");
	shell->cwd = ft_strjoin(tmp, ARROW);
	free(cwd);
	free(tmp);
}

int	handle_exec_node(t_shell *shell, void *root, int *status)
{
	t_exec	*exec;

	exec = NULL;
	if (((t_node *)root)->type == N_EXEC)
	{
		exec = (t_exec *)root;
		if (is_parent_builtin(exec))
		{
			exec->argv = expand_argv(shell, exec->argv);
			exec_parent_builtin(shell, exec);
			free_expand(exec->argv);
			return (1);
		}
		else
		{
			if (fork() == 0)
				exec_tree(shell, root);
			waitpid(-1, status, 0);
			exit_status(*status);
			return (1);
		}
	}
	return (0);
}

void	exec_processes(t_shell *shell, void *root)
{
	int		status;

	status = 0;
	set_main_signals();
	handle_heredoc(shell, root);
	if (handle_exec_node(shell, root, &status))
		return ;
	if (fork() == 0)
		exec_tree(shell, root);
	waitpid(-1, &status, 0);
	exit_status(status);
}

int	is_env_empty(t_shell *shell)
{
	return (shell->envp == NULL || ft_lstsize(shell->envp) == 0);
}

void	reset_shell(t_shell *shell)
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
