/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:14:07 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 18:08:31 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("[%s]➜", (char *)lst->content);
		lst = lst -> next;
	}
	printf("0\n");
}

void	print_token_lst(t_list *lst)
{
	t_token	*token;

	printf("+-----------------+------------+--------------+--------+\n");
	printf("|     Value       |    Type    |    State     |  Pos   |\n");
	printf("+-----------------+------------+--------------+--------+\n");
	while (lst)
	{
		token = (t_token *)lst->content;
		printf("| %-15s | ", token->value);

		// Print the type
		if (token->type == WORD)
			printf("%-10s | ", "WORD");
		else if (token->type == PIPE)
			printf("%-10s | ", "PIPE");
		else if (token->type == APPEND)
			printf("%-10s | ", "APPEND");
		else if (token->type == OUTFILE)
			printf("%-10s | ", "OUTFILE");
		else if (token->type == INFILE)
			printf("%-10s | ", "INFILE");

		// Print the state
		if (token->state == GENERAL)
			printf("%-12s | ", "GENERAL");
		else if (token->state == IN_DQUOTES)
			printf("%-12s | ", "IN_DQUOTES");
		else if (token->state == IN_SQUOTES)
			printf("%-12s | ", "IN_SQUOTES");

		// Print the position
		printf("%-6d |\n", token->pos);

		// Move to the next token in the list
		lst = lst->next;
	}
	printf("+-----------------+------------+--------------+--------+\n");
}

void	print_cmd_lst(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->input[i])
	{
		printf("item: %s\n", shell->input);
		i++;
	}
}
