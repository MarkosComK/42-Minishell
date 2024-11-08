/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:16:31 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 11:43:36 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

//signals.c
void	sig_main(int signo);
void	set_main_signals(void);
void	handle_signals(void);
void	set_fork1_signal(void);

//signals_heredoc.c
t_shell	*shell_struct(t_shell *shell, int flag);
void	sigint_heredoc_handler(int sig);
void	heredoc_signal(void);

#endif
