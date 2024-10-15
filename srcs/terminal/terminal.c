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
	char	*input;

	input = readline(B_RED PROMPT DEFAULT);
	if (input)
		add_history(input);
	if (input_validation(input))
	{
		terminal(shell);
	}
	if (input == NULL || !ft_strcmp(input, "exit") || input_validation(input))
	{
		free(input);
		return ;
	}
	lexer(shell, input);
	print_token_lst(shell->token_lst);
	printf("You entered: %s\n", input);
	free(input);
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
}
