/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:07:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:07:54 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_outfiles(char **outfiles, int space)
{
	int	i;

	i = 0;
	while (i < space + 2)
	{
		printf(" ");
		i++;
	}
	printf("[OUTFILES]: ");
	i = 0;
	while (outfiles[i])
	{
		printf("%s", outfiles[i]);
		if (outfiles[i + 1])
			printf(", ");
		i++;
	}
	printf("\n");
}

void	print_exec(char **argv, int space)
{
	int i;
	int j;

	j = 0;
	while (argv[j])
	{
		i = 0;
		while (i < space + 2)
		{
			printf(" ");
			i++;
		}
		printf("[%s]\n", argv[j]);
		j++;
	}
}

void	print_infiles(char **outfiles, int space)
{
	int	i;

	i = 0;
	while (i < space + 2)
	{
		printf(" ");
		i++;
	}
	printf("[INFILES]: ");
	i = 0;
	while (outfiles[i])
	{
		printf("%s", outfiles[i]);
		if (outfiles[i + 1])
			printf(", ");
		i++;
	}
	printf("\n");
}

void	print_bst_exec(t_exec *node, int space)
{
	int	i;

	i = 0;
	if (node->outfiles)
		print_outfiles(node->outfiles, space);
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("[EXEC]\n");
	if (node->argv)
	{
		print_exec(node->argv, space);
	}
	if (node->infiles)
		print_infiles(node->infiles, space);
}
