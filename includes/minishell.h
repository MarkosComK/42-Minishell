/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:22:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/27 17:36:58 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <binary_tree.h>
# include <builtins.h>
# include <colors.h>
# include <environment.h>
# include <errno.h>
# include <errors.h>
# include <exec.h>
# include <fcntl.h>
# include <input.h>
# include <libft.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signals.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <structs.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <terminal.h>
# include <tokenization.h>
# include <utils.h>

// MACROS
# define PROMPT "🔥 HELLSH ➜ "
# define MINISHELL YELLOW "hellsh"

/*metacharaters
 * A character that, when unquoted, separates words. A metacharacter is a space
 * , tab, newline, or one of the following characters:
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’
 */
# define METACHARS "|;<>"

extern int	e_signo;

// check_args.c
int			check_args(int argc, char *argv[], char *envp[]);
int			exit_code(int value);
#endif
