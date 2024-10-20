/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:18:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:34:04 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *find_cmd_path(t_list *path_list, const char *command)
{
    char *cmd_path;
    char *only_path;
    t_list *current;

    // Iterate through the linked list of PATH directories
    current = path_list;
    while (current != NULL)
    {
        char *path_dir = (char *)current->content;

        // Use ft_strjoin to concatenate the path and command
        only_path = ft_strjoin(path_dir, "/");
        if (!only_path)
        {
            perror("ft_strjoin");
            return NULL;
        }

        cmd_path = ft_strjoin(only_path, command); // Combine with the command
        free(only_path);  // Free the intermediate result after use

        if (!cmd_path)
        {
            perror("ft_strjoin");
            return NULL;
        }

        // Check if the file exists and is executable
        if (access(cmd_path, F_OK | X_OK) == 0)
        {
            return cmd_path;  // Command found, return the full path
        }

        free(cmd_path);  // Free the allocated memory if command not found
        current = current->next;  // Move to the next directory in the list
    }

    // If the command was not found in any directory, return NULL
    return NULL;
}
