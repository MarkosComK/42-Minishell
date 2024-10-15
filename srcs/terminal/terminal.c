/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 12:31:01 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell)
{
	ft_bzero(shell, sizeof(t_shell));
	shell->input = readline(B_RED PROMPT DEFAULT);
	if (shell->input && shell->input[0] != '\0')
		add_history(shell->input);
	if (input_validation(shell))
	{
		free_shell(shell);
		terminal(shell);
	}
	if (shell->input == NULL || !ft_strcmp(shell->trim_input, "exit"))
	{
		free_shell(shell);
		return ;
	}
	lexer(shell, shell->input);
	print_token_lst(shell->token_lst);
	free_shell(shell);
	terminal(shell);
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
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	ft_bzero(shell, sizeof(t_shell));
}
