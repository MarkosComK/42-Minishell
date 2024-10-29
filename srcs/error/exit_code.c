/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:37:44 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:12:29 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*itoa_exit(t_shell *shell, char **str)
{
	char	*code;

	code = ft_itoa(exit_code(-1));
	if (!code)
		exit_failure(shell, "itoa_exit");
	*str = ft_strjoin(*str, code);
	free(code);
	if (!code)
		exit_failure(shell, "itoa_exit_2");
	return (*str);
}

int	exit_code(int value)
{
	static int	code = 0;

	if (value == -1)
		return (code);
	code = value;
	return (code);
}
