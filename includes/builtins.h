
#ifndef BUILTINS_H
#define BUILTINS_H

# include <structs.h>
# include <binary_tree.h>

//EXEC
int exec_builtin(t_exec *exec_node);
int is_builtin(const char *command);

//ECHO
int		ft_echo(t_exec *exec_node);
int		echo_flag_n(char *arg);
void	echo_output(char **args, int idx, int newline);


void test_echo(void);









#endif