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

int is_env_empty(t_shell *shell)
{
    return (shell->envp == NULL || ft_lstsize(shell->envp) == 0);
}

void init_shell_command(t_shell *shell)
{
    shell->input = NULL;
    shell->trim_input = NULL;
    shell->token_lst = NULL;
    shell->root = NULL;
    shell->cmd_path = NULL;
    shell->cwd = NULL;
    shell->path = NULL;
    shell->envp_arr = NULL;
}
