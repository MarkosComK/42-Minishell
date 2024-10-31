/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:16:31 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/23 11:47:55 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

//signals.c
void	sig_main(int signo);
void	set_main_signals(void);
void	handle_signals(void);
void	sig_fork1(int signo);
void	set_fork1_signal(void);

#endif
