/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:25:36 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:07:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*env_list(char **envp)
{
	t_list	*env_list;
	char	*content;

	env_list = NULL;
	if (!envp || !*envp)
		return (printf("empty env\n"), NULL);
	while (*envp)
	{
		content = ft_strdup(*envp);
		ft_lstadd_back(&env_list, ft_lstnew(content));
		(envp)++;
	}
	print_env_lst(env_list);
	return (env_list);
}
