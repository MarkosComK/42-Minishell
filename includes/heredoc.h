/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:42:13 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:03 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

void	set_exec(t_shell *shell, t_exec *exec);
int		run_heredoc(t_shell *shell, t_inf *infile, int fd);
void	traverse_pipe(t_shell *shell, t_pipe *pipe);
void	handle_heredoc(t_shell *shell, void *root);

#endif
