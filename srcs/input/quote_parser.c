/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:56:15 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/15 12:04:18 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 *	If not quoted, if a backslash followed by any character:
 *	skip the backslash and the following character (increment
 *	the string pointer twice).
 *	If not quoted, if a single quote and the previous character
 *	is not a backslash: replace the single quote with -1.
 *	ASCII codes: Single quote (') is ASCII 39, backslash (\) is ASCII 92.
 *	EX:
 *	Original string: This is a 'string with spaces' and a backslash \ space
 *	Modified string: This-is-a-'string with spaces'-and-a-backslash-\ space
 *
int	main()
{
	int		exit_code = 1;

	ft_printf("Original string: %s\n", argv[1]);
	argv = quote_space_parser(argc, argv);
	ft_printf("Modified string: %s\n", argv[1]);
	return (exit_code);
}
 */
/*
char	*quote_space_parser(char *argv)
{
	int		count;
	char	*new;
	char	*dequoted;

	count = counter(argv, 39);
	if (count % 2 != 0)
	{
		ft_putstr_fd("Quote error (odd number). Pipex exiting.\n", 2);
		exit(EXIT_FAILURE);
	}
	new = space_to_minus(argv);
	dequoted = dequote_single(new);
	return (dequoted);
}
*/
/* nb of single quotes not escapped by \ */
/*
int	counter(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		if (i > 0 && *str == c && *(str - 1) == '\\')
			i--;
		str++;
	}
	return (i);
}
*/
//might be necessary change '-' to -1
/*
char	*space_to_minus(char *str)
{
	int			in_quote;
	int			i;

	in_quote = 0;
	i = -1;
	while (str[++i])
	{
		if (!in_quote && str[i] == 39)
			in_quote = 1;
		else if (in_quote && str[i] == 39)
			in_quote = 0;
		else if (!in_quote && str[i] == 92 && str [i + 1] == ' ')
			i++;
		else if (!in_quote && str[i] == ' ')
			str[i] = '-';
	}
	return (str);
}
*/
/*
 * Remove the single quote from the *STR but only when it's not
 * part of a escape sequence. For EX:
 * Input string:    "This is a 'string' with a backslash \\
 * and a single quote \'"
 * Expected output: "This is a string with a backslash \ and a single quote '"
 */
// Remove single quotes not part of an escape sequence
/*
char	*dequote_single(char *str)
{
    int i = 0, j = 0;
    int len = strlen(str);
    char *new = malloc(len + 1); // Allocate memory for new string

    if (!new)
        return NULL; // Handle memory allocation failure

    while (str[i])
    {
        if (str[i] != 39 && str[i] != '\\')
            new[j++] = str[i];
        else if (str[i] == '\\' && str[i + 1] != 39 && str[i + 1] != ' ')
            new[j++] = str[i];
        else if (i > 0 && str[i] == 39 && str[i - 1] == '\\')
            new[j++] = str[i];
        i++;
    }
    new[j] = '\0'; // Null-terminate the new string
    return new; // Return the dequoted string
}
*/
