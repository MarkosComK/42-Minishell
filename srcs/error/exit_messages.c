/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:48:20 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:32:16 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exit_failure(t_shell *shell, char *function)
{
	free_shell(shell);
	ft_putstr_fd(RED"malloc error: "DEFAULT, 2);
	ft_putendl_fd(function, 2);
	exit(1);
}

void	infile_failure(t_shell *shell, char *file)
{
	struct stat	file_stat;
	char		*err_msg;

	errno = 0;
	ft_bzero(&file_stat, sizeof(file_stat));
	stat(file, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		err_msg = ": Is a directory";
	else if (errno == ENOENT)
		err_msg = ": No such file or directory";
	else if (errno == EACCES || !(file_stat.st_mode & S_IWUSR))
		err_msg = ": Permission denied";
	else
		return ;
	path_message(shell, file, err_msg);
	exit(1);
}

void	outfile_failure(t_shell *shell, char *file)
{
	struct stat	file_stat;
	char		*err_msg;

	errno = 0;
	ft_bzero(&file_stat, sizeof(file_stat));
	stat(file, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
		err_msg = ": Is a directory";
	else if (errno == ENOENT)
		err_msg = ": No such file or directory";
	else if (errno == EACCES || !(file_stat.st_mode & S_IWUSR))
		err_msg = ": Permission denied";
	else
		return ;
	path_message(shell, file, err_msg);
	exit(1);
}

//tem coisa inutil aqui mas fdase
void	is_directory(t_shell *shell, char *path)
{
	struct stat	path_stat;
	char		*error_msg;
	int			exit_code;

	if (!path || !ft_strchr(path, '/'))
		return ;
	errno = 0;
	exit_code = 126;
	error_msg = NULL;
	ft_bzero(&path_stat, sizeof(path_stat));
	stat(path, &path_stat);
	if (errno == ENOENT)
	{
		error_msg = ": No such file or directory";
		exit_code = 127;
	}
	else if (S_ISDIR(path_stat.st_mode))
		error_msg = ": Is a directory";
	else if (errno == EACCES || !(path_stat.st_mode & S_IWUSR))
		error_msg = ": Permission denied";
	if (error_msg)
	{
		path_message(shell, path, error_msg);
		exit(exit_code);
	}
}

void	exec_failure(t_shell *shell, char *cmd, char **argv)
{
	(void) cmd;
	if (argv && argv[0])
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_shell(shell);
		exit(127);
	}
	free_shell(shell);
	exit(0);
}
