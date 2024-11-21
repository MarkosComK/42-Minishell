/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:54:55 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:04 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	dup_file2(char *name, int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	free(name);
}

void	dup_file(char *name, int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	free(name);
}
