/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:29 by hluiz-ma         ###   ########.fr       */
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
	shell->root = build_tree(shell, shell->token_lst);
	set_main_signals();
	exec_processes(shell);
	free_shell(shell);
	terminal(shell, envp);
}

void	del_token(void *content)
{
	t_token *token;

	token = (t_token *)content;
	if (token)
	{
		free(token->value);
		free(token);
	}
}

void	free_shell(t_shell *shell)
{
	//t_list	*tmp;
	int		i;

	//tmp = shell->token_lst;
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
	/*
	while (shell->path)
	{
		tmp = shell->path->next;
		free(shell->path->content);
		free(shell->path);
		shell->path = tmp;
	}
	*/
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->root)
		free_bst(shell->root);
	if (shell->cmd_path)
		free(shell->cmd_path);
	if (shell->cwd)
		free(shell->cwd);
	finish_shell(shell);
}
