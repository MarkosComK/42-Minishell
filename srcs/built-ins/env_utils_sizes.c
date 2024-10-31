/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_sizes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:59:43 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/31 16:00:05 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	content_size(char *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	while (env[j] && env[j] != '\0')
		j++;
	return (j - i);
}

int	val_size(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	return (i);
}
