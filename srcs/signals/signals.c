/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:15:08 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/23 12:28:15 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void signal_handler(int sig)
{
	printf("executing parent\n");
	// Ignore the signal, or do any custom behavior if needed
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void signal_handler_child(int sig)
{
	printf("executing child\n");
	// Ignore the signal, or do any custom behavior if needed
	(void)sig;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	//rl_on_new_line();
	rl_redisplay();
}

void	handle_signal(void)
{
	struct sigaction sa;

	// Set up the sigaction structure to ignore SIGINT
	sa.sa_handler = signal_handler;  // Handler function
	sa.sa_flags = 0;  // No special flags
	sigemptyset(&sa.sa_mask);  // Do not block any signals while handling

	// Install the signal handler for SIGINT (Ctrl-C)
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	handle_signal_parent(void)
{
	struct sigaction sa;

	sa.sa_handler = SIG_IGN;  // ignore signal when in parent process
	sa.sa_flags = 0;  // No special flags
	sigemptyset(&sa.sa_mask);  // Do not block any signals while handling

	// Install the signal handler for SIGINT (Ctrl-C)
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	handle_signal_child(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler_child;  // Handler function
	sa.sa_flags = 0;  // No special flags
	sigemptyset(&sa.sa_mask);  // Do not block any signals while handling

	// Install the signal handler for SIGINT (Ctrl-C)
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}
