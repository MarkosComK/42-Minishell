/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:03:28 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/11 14:12:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

	i = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '*') && is_valid_wildcard(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_matches(char *token)
{
	DIR			*dir;
	t_dirent	*entry;
	t_list		*matches;
	t_list		*new;

	matches = NULL;
	dir = opendir(".");
	if (!dir)
		return (NULL);
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] == '.' && token[0] != '.')
			continue ;
		if (match_pattern(token, entry->d_name))
		{
			new = pattern_new(entry->d_name);
			if (!new)
			{
				ft_lstclear(&matches, free);
				closedir(dir);
				return (NULL);
			}
			ft_lstadd_back(&matches, new);
		}
	}
	closedir(dir);
	return (matches);
}
/*
void	check_wildcards(t_shell *shell, t_exec *exec_node)
{
	char	**expanded_argv;
	char	*cmd_backup;

	if (!exec_node || !exec_node->argv || !has_wildcard(exec_node->argv))
		return ;
	cmd_backup = ft_strdup(exec_node->command);
	if (!cmd_backup)
		exit_failure(shell, "command backup failed");
	expanded_argv = process_wildcards(exec_node->argv);
	if (!expanded_argv)
	{
		free(cmd_backup);
		exit_failure(shell, "wildcard expansion failed");
	}
	if (expanded_argv == exec_node->argv)
	{
		free(cmd_backup);
		return ;
	}
	free(exec_node->command);
	exec_node->command = cmd_backup;
	exec_node->argv = expanded_argv;
}*/

void    check_wildcards(t_shell *shell, t_exec *exec_node)
{
    char    **expanded_argv;
    char    *cmd_backup;
    int     i;

    printf("\n[CHECK_WILDCARDS] Iniciando...\n");
    if (!exec_node || !exec_node->argv || !has_wildcard(exec_node->argv))
    {
        printf("[CHECK_WILDCARDS] Condições não atendidas\n");
        return;
    }

    printf("[CHECK_WILDCARDS] Argumentos originais:\n");
    i = 0;
    while (exec_node->argv[i])
    {
        printf("  argv[%d]: '%s'\n", i, exec_node->argv[i]);
        i++;
    }

    expanded_argv = process_wildcards(exec_node->argv);
    if (!expanded_argv)
    {
        printf("[CHECK_WILDCARDS] Falha na expansão\n");
        exit_failure(shell, "wildcard expansion failed");
    }

    printf("[CHECK_WILDCARDS] Argumentos após expansão:\n");
    i = 0;
    while (expanded_argv[i])
    {
        printf("  expanded[%d]: '%s'\n", i, expanded_argv[i]);
        i++;
    }

    if (expanded_argv == exec_node->argv)
    {
        printf("[CHECK_WILDCARDS] Não houve expansão\n");
        return;
    }

    cmd_backup = ft_strdup(expanded_argv[0]);
    if (!cmd_backup)
    {
        printf("[CHECK_WILDCARDS] Falha no backup do comando\n");
        ft_free_arr(expanded_argv);
        exit_failure(shell, "command backup failed");
    }

    printf("[CHECK_WILDCARDS] Atualizando comando e argumentos\n");
    printf("  Comando antigo: '%s'\n", exec_node->command);
    printf("  Comando novo: '%s'\n", cmd_backup);

    ft_free_arr(exec_node->argv);
    exec_node->argv = expanded_argv;
    free(exec_node->command);
    exec_node->command = cmd_backup;
    printf("[CHECK_WILDCARDS] Finalizado\n\n");
}