
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:37:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:44:51 by marsoare         ###   ########.fr       */
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
	//ft_putendl_fd(": No such file or directory", 2);
	free_shell(shell);
	exit(1);
}

//tem coisa inutil aqui mas fdase
void	is_directory(t_shell *shell, char *path, char *cmd)
{
	struct stat	path_stat;

	errno = 0;
	(void) cmd;
	stat(path, &path_stat);
	if (ft_strnstr(path, "./", ft_strlen(path))
		|| ft_strnstr(path, "/.", ft_strlen(path))
		|| ft_strnstr(path, "/", ft_strlen(path)))
	{
		ft_putstr_fd(MINISHELL " " DEFAULT, 2);
		ft_putstr_fd(path, 2);
		free_shell(shell);
		if (errno == ENOENT)
		{
			ft_putendl_fd(": No such file or directory", 2);
			exit(127);
		}
		else if (S_ISDIR(path_stat.st_mode))
		{
			ft_putendl_fd(": Is a directory", 2);
			exit(126);
		}
	}
}

void	exec_failure(t_shell *shell, char *cmd, char **argv)
{
	(void) cmd;
	if (argv)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": command not found", 2);
	}
	free_shell(shell);
	exit(127);
}
