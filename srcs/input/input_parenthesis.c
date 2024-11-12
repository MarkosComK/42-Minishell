/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:42:05 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/12 11:09:05 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	balance_message(int balance)
{
	if (balance == -1)
		ft_putendl_fd(CLOSE_ERROR, 2);
	else if (balance > 0)
		ft_putendl_fd(OPEN_ERROR, 2);
	else if (balance < 0)
		ft_putendl_fd(CLOSE_ERROR, 2);
}

bool	check_parenthesis(char *str)
{
	int	balance;
	int	i;

	balance = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ')' && balance == 0)
			return (balance_message(-1), false);
		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
			balance--;
		i++;
	}
	if (balance != 0)
		balance_message(balance);
	if (balance == 0)
		return (true);
	return (false);
}
