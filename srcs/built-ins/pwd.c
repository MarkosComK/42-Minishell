/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:14 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:58 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_pwd(t_exec *exec_node)
{
	e_signo = 0;
	if (exec_node->argv[1])
	{
		printf("pwd: too many arguments\n");
		e_signo = 2;
	}
	else
		ft_pwd();
	return (e_signo);
}

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("pwd error:");
		e_signo = 2;
	}
}
