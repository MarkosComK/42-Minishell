

#include <minishell.h>

int is_builtin(const char *command)
{
    const char *builtins[8];
    int i;

    i = 0;
    builtins[0] = "echo";
    builtins[1] = "cd";
    builtins[2] = "pwd";
    builtins[3] = "export";
    builtins[4] = "unset";
    builtins[5] = "env";
    builtins[6] = "exit";
    builtins[7] = NULL;
    while (builtins[i])
    {
        if (ft_strcmp(command, builtins[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}


int exec_builtin(t_exec *exec_node)
{
    if (ft_strcmp(exec_node->argv[0], "echo") == 0)
        return ft_echo(exec_node);

    return 1;
}

