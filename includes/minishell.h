/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:22:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:17 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <structs.h>
# include <colors.h>
# include <stdbool.h>
# include <input.h>
# include <terminal.h>
# include <errors.h>
# include <tokenization.h>
# include <utils.h>
# include <builtins.h>
# include <binary_tree.h>
# include <environment.h>
# include <exec.h>
# include <sys/wait.h>
# include <fcntl.h>

// MACROS
# define PROMPT "🔥 HELLSH ➜ "

/*metacharaters
 * A character that, when unquoted, separates words. A metacharacter is a space
 * , tab, newline, or one of the following characters:
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’
*/
# define METACHARS "|;<>"


//check_args.c
int	check_args(int argc, char *argv[], char *envp[]);
#endif
