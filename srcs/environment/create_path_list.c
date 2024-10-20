/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:39:45 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 14:43:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*path_list(char **envp)
{
	t_list	*path_list;
	char	*path;
	(void)	envp;

	path_list = NULL;
	path = getenv("PATH");
	printf("%s\n", path);


	return (path_list);
}
