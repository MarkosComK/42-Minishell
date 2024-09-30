/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 17:06:51 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell)
{
	char	*input;

	while (1)
	{
		input = readline(B_RED PROMPT DEFAULT);
		input_validation(input);
		shell->input = ft_split(input, ' ');
		print_cmd_lst(shell);
		lexer(shell);
		if (input == NULL || !ft_strcmp(input, "exit"))
		{
			printf("\nExiting shell...\n");
			break;
		}
		if (input)
			add_history(input);
		printf("You entered: %s\n", input);
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
	ft_lstiter(shell->token_lst, free);
}
