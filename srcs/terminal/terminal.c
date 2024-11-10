/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 13:24:02 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell, char **envp)
{
	start_shell(shell);
	handle_signals();
	shell_input(shell);
	shell->input = readline(shell->cwd);
	if (shell->input && shell->input[0] != '\0')
		add_history(shell->input);
	if (shell->input && input_validation(shell))
	{
		free_shell(shell);
		terminal(shell, envp);
	}
	if (shell->input == NULL || !ft_strcmp(shell->trim_input, "exit"))
	{
		free_shell(shell);
		return ;
	}
	lexer(shell, shell->trim_input);
	shell->envp_arr = env_arr(shell);
	shell->path = path_list(shell, envp);
	shell->root = build_ltree(shell, shell->token_lst);
	//print_token_lst(shell->token_lst);
	//ltree_print(shell->root, 1);
	lexec_tree(shell, shell->root);
	free_shell(shell);
	last_process(0);
	terminal(shell, envp);
}

void	free_shell(t_shell *shell)
{
	int		i;

	ft_lstclear(&shell->token_lst, del_token);
	i = 0;
	if (shell->envp_arr)
	{
		while (shell->envp_arr[i])
		{
			free(shell->envp_arr[i]);
			i++;
		}
		free(shell->envp_arr);
	}
	ft_lstclear(&shell->path, free);
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->root)
		ltree_free(shell->root);
	if (shell->cmd_path)
		free(shell->cmd_path);
	if (shell->cwd)
		free(shell->cwd);
	finish_shell(shell);
}
