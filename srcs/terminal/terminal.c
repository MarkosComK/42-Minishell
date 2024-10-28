/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/24 05:07:49 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		exit_code(int	value)
{
	static int	code = 0;

	code = value;
	//printf("exit code: %i\n", code);
	return (code);
}

void	shell_input(t_shell *shell)
{
	char	*prompt;
	char	cwd[PATH_MAX];
	char	*tmp;

	getcwd(cwd, sizeof(cwd));
	prompt = "\001" B_RED "\002Minishell\001" DEFAULT "\002";
	tmp = ft_strjoin(prompt, cwd);
	shell->cwd = ft_strjoin(tmp, "\001" B_RED "\002 → \001" DEFAULT "\002");
	free(tmp);
}

void	terminal(t_shell *shell, char **envp)
{
	ft_bzero(shell, sizeof(t_shell));
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
	set_main_signals();
	lexer(shell, shell->trim_input);
	shell->envp = env_list(shell, envp);
	shell->envp_arr = env_arr(shell);
	/*
	for (int i = 0; shell->envp_arr[i]; i++)
		printf("%s\n", shell->envp_arr[i]);
		*/
	shell->path = path_list(shell, envp);
	shell->root = build_tree(shell, shell->token_lst);
	//print_env_lst(shell->envp);
	//print_token_lst(shell->token_lst);
	//print_bst(shell->root, 5);
	if (fork() == 0)
		exec_tree(shell, shell->root);
	wait(NULL);
	free_shell(shell);
	terminal(shell, envp);
}

void	free_shell(t_shell *shell)
{
	t_list	*tmp;
	t_token *token;

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
	while (shell->envp)
	{
		tmp = shell->envp->next;
		free(shell->envp->content);
		free(shell->envp);
		shell->envp= tmp;
	}
	int i = 0;
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
		shell->path= tmp;
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
	ft_bzero(shell, sizeof(t_shell));
}
