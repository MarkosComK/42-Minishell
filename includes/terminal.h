/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:06 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/09 17:40:48 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <structs.h>

//terminal.c
void	terminal(t_shell *shell, char **envp);
void	prepare_shell(t_shell *shell, char **envp);
void	execute_command(t_shell *shell, int *status);
int		is_env_empty(t_shell *shell);
void	free_shell(t_shell *shell);

//terminal_utils.c
void	shell_input(t_shell *shell);
void	exec_processes(t_shell *shell, void *root);
int		is_env_empty(t_shell *shell);
void	reset_shell(t_shell *shell);

#endif
