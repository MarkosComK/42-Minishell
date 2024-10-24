

#include <minishell.h>

int	execute_node(t_exec *exec_node)
{
	if (strcmp(exec_node->command, "echo") == 0)
		return ft_echo(exec_node);


	return -1;
}