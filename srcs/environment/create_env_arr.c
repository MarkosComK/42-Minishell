/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:58 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/22 14:25:13 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**env_arr(t_shell *shell)
{
	t_list	*envp_list;
	char	**env_arr;
	int		i;
	
	envp_list = shell->envp;
	i = ft_lstsize(envp_list);
	env_arr = malloc(sizeof(char *) * (i + 1));
	if (!env_arr)
		exit_failure(shell, "env_arr");
	i = 0;
	while (envp_list)
	{
		env_arr[i] = ft_strdup(envp_list->content);
		if (!env_arr[i])
			exit_failure(shell, "env_arr_1");
		envp_list = envp_list->next;
		i++;
	}
	env_arr[i] = NULL;
	return (env_arr);
}
