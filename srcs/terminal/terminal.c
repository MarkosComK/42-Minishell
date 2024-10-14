/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 18:39:35 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell)
{
	char	*input;

	input = readline(B_RED PROMPT DEFAULT);
	input_validation(input);
	lexer(shell, input);
	print_token_lst(shell->token_lst);
	if (input == NULL || !ft_strcmp(input, "exit"))
	{
		free(input);
		free_shell(shell);
		return ;
	}
	if (input)
		add_history(input);
	printf("You entered: %s\n", input);
	free(input);
	free_shell(shell);
	terminal(shell);
}

void	free_shell(t_shell *shell)
{
	t_list	*tmp;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		free(shell->token_lst->content);
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
}
