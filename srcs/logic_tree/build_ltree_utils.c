/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ltree_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:40:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/10 10:47:14 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_token(t_list *node)
{
	return (node && (((t_token *)node->content)->type != AND_IF
			/*|| ((t_token *)node->content)->type != OR )*/));
}
