/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:12:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 13:24:49 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//do never touch this
char	*handle_expand(t_shell *shell, char *input, int i)
{
	char	*str;

	str = ft_strdup("");
	if (!str)
		exit_failure(shell, "handle_expand");
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

int	prcs_expansion(t_shell *shell, char **str, char *input, int i)
{
	int	flag;

	flag = 0;
	while (input[i] && !ft_isspace(input[i]) && !ft_ismeta(input, i))
	{
		while (input[i] == '$')
			i = expand_unquoted(shell, str, input, i);
		flag = ft_flag(input[i], &i, flag);
		while (input[i] && flag)
		{
			while (input[i] && input[i] != '$' && input[i] != '"')
				*str = ft_strjoin_char(*str, input[i++]);
			if (input[i] == '$' || input[i] == '"')
				i = expand_quoted(shell, str, input, i);
			flag = ft_flag(input[i], &i, flag);
		}
		if (input[i] && input[i] == '\'')
			i = expand_single(shell, str, input, i);
		else if (input[i] && !ft_ismeta(input, i) && !ft_isspace(input[i]))
			*str = ft_strjoin_char(*str, input[i++]);
	}
	return (i);
}

int	expand_unquoted(t_shell *shell, char **str, char *input, int i)
{
	const int		start = ++i;
	char			*tmp;
	char			*var_name;
	char			*var_value;

	while (input[i] && !ft_isspace(input[i])
		&& (ft_isalnum(input[i]) || input[i] == '_')
		&& !ft_ismeta(input, i))
		i++;
	if (input[i] == '?')
		return (*str = itoa_exit(shell, str), ++i);
	var_name = ft_substr(input, start, i - start);
	if (!var_name)
		exit_failure(shell, "expand_unquoted");
	var_value = sh_get_env(shell->envp, var_name);
	free(var_name);
	if (var_value && ft_strchr(var_value, ' ') && !**str)
		return (tokenize_input(shell, var_value), i);
	if (var_value)
	{
		tmp = *str;
		*str = ft_strjoin(*str, var_value);
		free(tmp);
	}
	return (i);
}

int	expand_quoted(t_shell *shell, char **str, char *input, int i)
{
	int		start;
	char	*tmp;
	char	*var_name;
	char	*var_value;

	start = ++i;
	while (input[i] && !ft_isspace(input[i])
		&& (ft_isalnum(input[i]) || input[i] == '_')
		&& input[i] != '"')
		i++;
	if (input[i] == '?')
		return (*str = itoa_exit(shell, str), ++i);
	var_name = ft_substr(input, start, i - start);
	if (!var_name)
		exit_failure(shell, "expand_unquoted");
	var_value = getenv(var_name);
	free(var_name);
	if (var_value)
	{
		tmp = *str;
		*str = ft_strjoin(*str, var_value);
		free(tmp);
	}
	return (i);
}

int	expand_single(t_shell *shell, char **str, char *input, int i)
{
	int		start;
	char	*tmp;
	char	*subs;

	start = ++i;
	while (input[i] && input[i] != '\'')
		i++;
	subs = ft_substr(input, start, i - start);
	if (!subs)
		exit_failure(shell, "expand_unquoted");
	tmp = *str;
	*str = ft_strjoin(*str, subs);
	if (!subs)
		exit_failure(shell, "expand_unquoted_1");
	free(tmp);
	free(subs);
	return (i + 1);
}
