/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:12:39 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 22:25:07 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strjoin_char(char *str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);  // Free the old string if needed
	return (new_str);
}

int	is_expand(char *c, int *i)
{
	if (c[0] == '$')
		return ( *i += 1, 1);
	if (c[1] == '$')
		return ( *i += 2, 2);
	return (0);
}

int	handle_expand(t_shell *shell, char *input, int i)
{
	t_token	*new_token;
	char	*str;
	int		start;

	str = ft_strdup("");
	if (!str)
		exit_failure(shell, "handle_expand");
	while (input[i])
	{
		if (input[i] == '$')
		{
			start = ++i;
			while (input[i] && !ft_isspace(input[i])
				&& (ft_isalnum(input[i]) || input[i] == '_')
				&& !ft_ismeta(input, i))
				i++;
			printf("start: %s\n", &input[start]);
			printf("end: %s\n", &input[i - 1]);
			char *var_name = ft_substr(input, start, i - start);
			char *var_value = getenv(var_name); // Get variable value
			printf("var_value: %s\n", var_value);
			free(var_name);
			if (var_value)
			{
				char *tmp = str;
				str = ft_strjoin(str, var_value);
				printf("result: %s\n", str);
				printf("end: %c\n", input[i]);
				free(tmp);
			}
		}
		if (ft_isspace(input[i]) || ft_ismeta(input, i))
			break ;
	}
	new_token = ft_calloc(1, sizeof(t_token));
	new_token->value = str;
	new_token->type = WORD;
	new_token->state = GENERAL;
	ft_lstadd_back(&shell->token_lst, ft_lstnew(new_token));
	while (ft_isspace(input[i]))
		i++;
	printf("return i: %c\n", input[i]);
	return (i);
}

/*
int	handle_expand(t_shell *shell, char *input, int i)
{
	char	*var_name;
	char	*var_value;
	int		start;

	// Check if we are inside quotes
	if (input[i] == '"')
		i++; // Skip the initial quote
	
	// Start after the '$' sign
	start = i + 1;
	i++;
	// Continue until you find a non-alphanumeric character or underscore
	while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
		i++;

	printf("end:%c\n", input[i]);
	// Extract the variable name
	var_name = ft_substr(input, start, i - start);
	printf("var_name: %s\n", var_name);

	if (!var_name)
		exit_failure(shell, "handle_expand");

	// Retrieve the environment variable value
	var_value = getenv(var_name);
	free(var_name);

	if (var_value)
	{
		// Add var_value to your token list or string handling
		printf(GREEN"Expanded: %s\n"DEFAULT, var_value);
		// Code to insert var_value into your token structure goes here
	}

	return (i);
}
*/
