/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:20 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	print_cd_error(char *path, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	if (path && *path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	return (1);
}

int	handle_chdir_error(char *path)
{
	if (errno == EACCES)
		return (print_cd_error(path, "Permission denied"));
	if (errno == ENOENT)
		return (print_cd_error(path, "No such file or directory"));
	if (errno == ENOTDIR)
		return (print_cd_error(path, "Not a directory"));
	if (errno == ENAMETOOLONG)
		return (print_cd_error(path, "File name too long"));
	return (print_cd_error(path, strerror(errno)));
}
