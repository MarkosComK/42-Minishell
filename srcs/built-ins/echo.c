

#include <minishell.h>

int	ft_echo(t_exec *exec_node)
{
	bool newline;
	unsigned int i;

	newline = true;
	i = 1;
	if (exec_node->argv[i] && echo_flag_n(exec_node->argv[i]))
	{
		newline = false;
		i++;
	}

	echo_output(exec_node->argv, i, newline);

	return 0;
}

int	echo_flag_n(char *arg)
{
	int i;

	if (arg[0] != '-')
		return 0;
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return 0;
		i++;
	}
	return 1;
}

void    echo_output(char **args, int idx, int newline)
{
	unsigned int i;

	i = idx;
	while (args[i])
	{
        ft_putstr(args[i]);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}

	if (newline)
		write(1, "\n", 1);
}
