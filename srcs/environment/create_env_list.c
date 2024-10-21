/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:25:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 12:54:16 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*env_list(char **envp)
{
	t_list	*env_list;
	int		i;

	env_list = NULL;
	if (!envp || !*envp)
		return (printf("empty env\n"), NULL);
	i = 0;
	while (**envp)
	{
		
	}
	return (env_list);
}
