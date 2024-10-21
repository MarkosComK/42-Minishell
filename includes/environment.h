/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:46:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/21 13:25:42 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include <structs.h>

//create_env_list.c
t_list	*env_list(t_shell *shell, char **envp);
//create_path_list.c
t_list	*path_list(char **envp);
int	get_path(t_list	**path_list, char *path, int i);
//environment_printers.c
void	print_env_lst(t_list *lst);
//find_command_path.c
char *find_cmd_path(t_list *path_list, char *command);

#endif
