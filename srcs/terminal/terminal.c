/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/11/03 20:49:29 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	shell_input(t_shell *shell)
{
	char	*prompt;
	char	cwd[PATH_MAX];
	char	*tmp;

	getcwd(cwd, sizeof(cwd));
	prompt = "\001" B_RED "\002Minishell\001" DEFAULT "\002";
	tmp = ft_strjoin(prompt, cwd);
	shell->cwd = ft_strjoin(tmp, "\001"B_RED"\002 → \001"DEFAULT"\002");
	free(tmp);
}

void	terminal(t_shell *shell, char **envp)
{
	t_exec	*exec = NULL;
	int		status = 0;

    start_shell(shell);	
	handle_signals();
	shell_input(shell);
	shell->input = readline(shell->cwd);
	if (shell->input && shell->input[0] != '\0')
		add_history(shell->input);
	if (shell->input && input_validation(shell))
	{
		free_shell(shell);
		terminal(shell, envp);
	}
	if (shell->input == NULL || !ft_strcmp(shell->trim_input, "exit"))
	{
		free_shell(shell);
		return ;
	}
	lexer(shell, shell->trim_input);
	shell->envp_arr = env_arr(shell);
	shell->path = path_list(shell, envp);
	shell->root = build_tree(shell, shell->token_lst);
	print_token_lst(shell->token_lst);
	print_bst(shell->root, 5);
	set_main_signals();
	if (((t_node *)shell->root)->type == N_EXEC)
	{
		exec = (t_exec *)shell->root;
		if (is_parent_builtin(exec))
			exec_parent_builtin(shell, exec);
	}
	else
	{
		if (fork() == 0)
			exec_tree(shell, shell->root);
		waitpid(-1, &status, 0);
	}
	exit_status(status);
	free_shell(shell);
	terminal(shell, envp);
}

void	free_shell(t_shell *shell)
{
	t_list	*tmp;
	t_token	*token;
	int		i;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		token = (t_token *) shell->token_lst->content;
		free(token->value);
		free(shell->token_lst->content);
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
	i = 0;
	if (shell->envp_arr)
	{
		while (shell->envp_arr[i])
		{
			free(shell->envp_arr[i]);
			i++;
		}
		free(shell->envp_arr);
	}
	while (shell->path)
	{
		tmp = shell->path->next;
		free(shell->path->content);
		free(shell->path);
		shell->path = tmp;
	}
	if (shell->input)
		free(shell->input);
	if (shell->trim_input)
		free(shell->trim_input);
	if (shell->root)
		free_bst(shell->root);
	if (shell->cmd_path)
		free(shell->cmd_path);
	if (shell->cwd)
		free(shell->cwd);
	finish_shell(shell);
}
