/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:07:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/29 21:10:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

void	print_outfiles(t_list *outfiles, int space)
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
	while (outfiles)
	{
		printf("%s", (char *)((t_outf *)outfiles->content)->name);
		if (outfiles->next)
			printf(", ");
		outfiles = outfiles->next;
	}
	printf("\n");
}

void	print_exec(char **argv, int space)
{
	int	i;
	int	j;

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

void	print_infiles(t_list *infiles, int space)
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
	while (infiles)
	{
		printf("%s", (char *)((t_inf *)infiles->content)->eof);
		if (infiles->next)
			printf(", ");
		infiles = infiles->next;
	}
	printf("\n");
}
