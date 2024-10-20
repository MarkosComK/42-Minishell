/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_printers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:59:15 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:00:01 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env_lst(t_list *lst)
{
	printf("ENV LIST:\n");
	while (lst)
	{
		printf("[%s]➜", (char *)lst->content);
		lst = lst -> next;
	}
	printf("NULL\n");
}
