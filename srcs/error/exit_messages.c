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
	ft_putstr_fd(YELLOW"hellsh: "DEFAULT, 2);
	perror(file);
	free_shell(shell);
	exit(1);
}

//tem coisa inutil aqui mas fdase
void	is_directory(t_shell *shell, char *path)
{
	struct stat	path_stat;

	errno = 0;
	stat(path, &path_stat);
	if (!path)
		return ;
	if (ft_strchr(path, '/'))
	{
		if (errno == ENOENT)
		{
			ft_putstr_fd(MINISHELL " " DEFAULT, 2);
			ft_putstr_fd(path, 2);
			free_shell(shell);
			ft_putendl_fd(": No such file or directory", 2);
			exit(127);
		}
		else if (S_ISDIR(path_stat.st_mode))
		{
			ft_putstr_fd(MINISHELL " " DEFAULT, 2);
			ft_putstr_fd(path, 2);
			free_shell(shell);
			ft_putendl_fd(": Is a directory", 2);
			exit(126);
		}
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

void	exit_message(char *bash, char *file, char *message)
{
	if (bash)
		ft_putstr_fd(bash, 2);
	if (file)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}
