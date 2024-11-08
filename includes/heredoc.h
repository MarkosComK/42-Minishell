/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:42:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/08 13:44:10 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

//heredoc.c
void	set_exec(t_shell *shell, t_exec *exec);
int		run_heredoc(t_shell *shell, t_inf *infile, int fd);
char	*ft_random_name(t_shell *shell, char *eof);
void	traverse_pipe(t_shell *shell, t_pipe *pipe);
void	handle_heredoc(t_shell *shell, void *root);

//heredoc_expand.c
char	*heredoc_expand(t_shell *shell, char *line);

//heredoc_process.c
void	heredoc_process(t_shell *shell, t_inf *inf, int fd);

#endif
