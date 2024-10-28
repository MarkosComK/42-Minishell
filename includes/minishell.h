/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:22:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 19:17:59 by hluiz-ma         ###   ########.fr       */
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
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <signals.h>
# include <limits.h>

// MACROS
# define PROMPT " Minihell:"
# define MINISHELL YELLOW"hellsh"

/*metacharaters
 * A character that, when unquoted, separates words. A metacharacter is a space
 * , tab, newline, or one of the following characters:
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’
*/
# define METACHARS "|;<>"

//check_args.c
int	check_args(int argc, char *argv[], char *envp[]);
int	exit_code(int value);
#endif
