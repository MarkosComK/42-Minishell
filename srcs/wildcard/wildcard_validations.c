/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:18 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_wildcards(t_shell *shell, t_exec *exec_node)
{
	char	**expanded_argv;
	char	**old_argv;
	char	*old_command;

	(void)shell;
	if (!exec_node || !exec_node->argv || !has_wildcard(exec_node->argv))
		return ;
	expanded_argv = process_wildcards(exec_node->argv);
	if (!expanded_argv || expanded_argv == exec_node->argv)
		return ;
	old_argv = exec_node->argv;
	old_command = exec_node->command;
	exec_node->argv = expanded_argv;
	exec_node->command = NULL;
	if (old_command)
		free(old_command);
	ft_free_arr(old_argv);
}

int	is_valid_wildcard(char *arg)
{
	if (ft_strcmp(arg, "*") == 0)
		return (1);
	if (ft_strchr(arg, '*'))
		return (1);
	return (0);
}

int	has_wildcard(char **argv)
{
	size_t	i;

	i = 1;
	if (!argv || !argv[0])
		return (0);
	while (argv && argv[i])
	{
		if (ft_strchr(argv[i], '*') && is_valid_wildcard(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_matches(char *token)
{
	t_dirent	*entry;
	t_list		*matches;

	matches = NULL;
	entry = NULL;
	matches = generate_matches(entry, token, matches);
	return (matches);
}
