/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:46:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 13:18:37 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**expand_argv(t_shell *shell, char **argv)
{
	char	**new_argv;
	char	*expand;
	int		i;
	int		j;

	i = 0;
	new_argv = NULL;
	while (argv[i])
		i++;
	new_argv = ft_calloc(i + 1, sizeof(char *));
	if (!new_argv)
		exit_failure(shell, "expand_argv");
	i = 0;
	j = 0;
	while (argv[i])
	{
		expand = handle_expand(shell, argv[i], 0);
		if (expand)
			new_argv[j++] = expand;
		else
			free(expand);
		i++;
	}
	free(argv);
	return (new_argv);
}

void	free_expand(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}
