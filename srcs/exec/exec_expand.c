/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:46:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 13:59:33 by marsoare         ###   ########.fr       */
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
	while (argv && argv[i])
		i++;
	new_argv = ft_calloc(i + 1, sizeof(char *));
	if (!new_argv)
		exit_failure(shell, "expand_argv");
	i = 0;
	j = 0;
	while (argv && argv[i])
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

char	*f(t_shell *shell, char *input)
{
	char	*str;
	int		i;

	str = ft_strdup("");
	if (!str)
		exit_failure(shell, "handle_expand");
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' || ft_isquote(input[i]))
			i = prcs_expansion(shell, &str, input, i);
		else
			while (input[i] && (input[i] != '$' && input[i] != '"'))
				str = ft_strjoin_char(str, input[i++]);
		if (ft_isspace(input[i]) || ft_ismeta(input, i))
			break ;
	}
	if (ft_strlen(str) == 0 && input[0] == '$')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
