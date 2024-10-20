/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:18:22 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/20 17:18:30 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *find_command_path(t_list *path_list, const char *command) {
    char *full_path;
    t_list *current;
    size_t len;

    // Iterate through the linked list of PATH directories
    current = path_list;
    while (current != NULL) {
        char *path_dir = (char *)current->content;
        
        // Allocate memory for the full path (directory + "/" + command)
        len = strlen(path_dir) + strlen(command) + 2; // +2 for '/' and null terminator
        full_path = (char *)malloc(len);
        if (!full_path) {
            perror("malloc");
            return NULL;
        }

        // Build the full path string (directory + "/" + command)
        snprintf(full_path, len, "%s/%s", path_dir, command);

        // Check if the file exists and is executable
        if (access(full_path, X_OK) == 0) {
            return full_path;  // Command found, return the full path
        }

        // Free the allocated memory for the full path if not found
        free(full_path);
        current = current->next;
    }

    // If the command was not found in any directory, return NULL
    return NULL;
}
