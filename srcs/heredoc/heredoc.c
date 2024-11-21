/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 13:56:46 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_exec(t_shell *shell, t_exec *exec)
{
	t_list	*infiles;
	t_inf	*inf;
	int		fd;

	infiles = exec->infiles;
	while (infiles)
	{
		inf = (t_inf *)infiles->content;
		if (inf->type == HERE)
		{
			inf->name = ft_random_name(shell, inf->eof);
			fd = open(inf->name, O_RDWR | O_CREAT | O_TRUNC, 0600);
			heredoc_process(shell, inf, fd);
		}
		infiles = infiles->next;
	}
}

char	*ft_random_name(t_shell *shell, char *eof)
{
	char		*name;
	static int	addr = 1;
	char		*ptr;
	int			num;

	num = (addr + (int)eof[0] + ft_strlen(eof) * addr);
	addr++;
	ptr = ft_itoa(num);
	name = ft_strjoin("/tmp/.heredoc_", ptr);
	free(ptr);
	if (!name)
		exit_failure(shell, "ft_random_name");
	return (name);
}

int	run_heredoc(t_shell *shell, t_inf *infile, int fd)
{
	char	*line;

	if (fd < 0)
		infile_failure(shell, infile->eof);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !ft_strcmp(line, infile->eof))
		{
			break ;
		}
		line = heredoc_expand(shell, line);
		write(fd, line, ft_strlen(line));
		free(line);
		write(fd, "\n", 1);
	}
	return (fd);
}

void	traverse_pipe(t_shell *shell, t_pipe *pipe)
{
	if (pipe->left)
		handle_heredoc(shell, pipe->left);
	if (pipe->right)
		handle_heredoc(shell, pipe->right);
}

void	handle_heredoc(t_shell *shell, void *root)
{
	shell_struct(shell, 0);
	if (((t_node *)root)->type == N_PIPE)
		traverse_pipe(shell, root);
	else if (((t_node *)root)->type == N_EXEC)
		set_exec(shell, root);
}
