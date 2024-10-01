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

	while (1)
	{
		input = readline(B_RED PROMPT DEFAULT);
		if (input == NULL || !ft_strcmp(input, "exit"))
		{
			printf("\nExiting shell...\n");
			free(input);
			break;
		}
		input_validation(input);
		lexer(shell, input);
		print_lst(shell->token_lst);
		if (input)
			add_history(input);
		free(input);
		free_shell(shell);
	}
}

void	free_shell(t_shell *shell)
{
	int	i;
	
	i = 0;
	while(shell->input[i])
		free(shell->input[i++]);
	free(shell->input);

	t_list	*tmp;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
}
