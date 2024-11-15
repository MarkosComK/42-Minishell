/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:22:19 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 12:29:44 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
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
# include <exec.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <signals.h>
# include <limits.h>
# include <heredoc.h>
# include <logic_tree.h>
# include <string.h>

// MACROS
# define ESC_START "\001\033[1;91m\002"
# define ESC_RESET "\001\033[0;93m\002"
# define PROMPT "Minishell ["
# define ESC_CODE "\001\033[1;91m\002] [\001\033[0;39m\002"
# define ARROW "\001\033[1;91m]\002 \001→\002 \001\033[0m\002"
# define MINISHELL "\001\033[0;93\002mminishell\001\033[0;39m\002\001\033[0m\002"

/*metacharaters
 * A character that, when unquoted, separates words. A metacharacter is a space
 * , tab, newline, or one of the following characters:
 * ‘|’, ‘&’, ‘;’, ‘(’, ‘)’, ‘<’, or ‘>’
*/
# define METACHARS "|;<>"

//check_args.c
int	check_args(int argc, char *argv[], char *envp[]);
#endif
