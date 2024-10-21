/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_printers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:59:15 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:09:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_env_lst(t_list *lst)
{
	printf("ENVIRONMENT:\n");
	printf("---------------------:\n");
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst -> next;
	}
	printf("---------------------:\n");
	printf("END\n");
}
