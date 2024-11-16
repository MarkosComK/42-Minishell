/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:10:59 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/16 18:12:59 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_exit(void)
{
	static int	value = 0;

	if (value == 0)
		ft_putstr_fd("exit\n", 1);
	value++;
}
