/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:33:58 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:22 by hluiz-ma         ###   ########.fr       */
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

int is_env_empty(t_shell *shell)
{
    return (shell->envp == NULL || ft_lstsize(shell->envp) == 0);
}

void finish_shell(t_shell *shell)
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

void start_shell(t_shell *shell)
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
