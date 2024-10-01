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

void	print_cmd_lst(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->input[i])
	{
		printf("item: %s\n", shell->input[i]);
		i++;
	}
}
