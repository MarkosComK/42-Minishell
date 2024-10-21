/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:11:33 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell, char **envp)
{
	ft_bzero(shell, sizeof(t_shell));
	shell->input = readline(B_RED PROMPT DEFAULT);
	if (shell->input && shell->input[0] != '\0')
		add_history(shell->input);
	if (input_validation(shell))
	{
		free_shell(shell);
		terminal(shell, envp);
	}
	if (shell->input == NULL || !ft_strcmp(shell->trim_input, "exit"))
	{
		free_shell(shell);
		return ;
	}
	lexer(shell, shell->input);
	shell->envp = env_list(envp);
	shell->path = path_list(envp);
	shell->root = build_tree(shell->token_lst);
	//print_env_lst(shell->path);
	//print_token_lst(shell->token_lst);
	//print_bst(shell->root, 5);
	if (fork() == 0)
		exec_tree(shell, shell->root);
	wait(NULL);
	free_shell(shell);
	terminal(shell, envp);
}

void	free_shell(t_shell *shell)
{
	t_list	*tmp;
	t_token *token;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		token = (t_token *) shell->token_lst->content;
		free(token->value);
		free(shell->token_lst->content);
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
	while (shell->envp)
	{
		tmp = shell->envp->next;
		free(shell->envp->content);
		free(shell->envp);
		shell->envp= tmp;
	}
	while (shell->path)
	{
		tmp = shell->path->next;
		free(shell->path->content);
		free(shell->path);
		shell->path= tmp;
	}
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->root)
		free_bst(shell->root);
	ft_bzero(shell, sizeof(t_shell));
}
