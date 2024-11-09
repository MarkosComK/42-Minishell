/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:20 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/10/27 18:46:08 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	set_new_pwd(t_shell *shell, char *old_pwd)
{
	char	*pwd;
	char	*pwd_var;
	char	*old_pwd_var;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (free(old_pwd), print_cd_error(NULL,
				"error retrieving current directory"));
	pwd_var = ft_strjoin("PWD=", pwd);
	old_pwd_var = ft_strjoin("OLDPWD=", old_pwd);
	if (!pwd_var || !old_pwd_var)
		exit_failure(shell, "cd: var allocation");
	export_var(shell, pwd_var);
	export_var(shell, old_pwd_var);
	free(pwd);
	free(pwd_var);
	free(old_pwd);
	free(old_pwd_var);
	return (0);
}

int	update_pwd_vars(t_shell *shell)
{
	char	*old_pwd;
	char	*path;

	path = sh_get_env(shell->envp, "PWD");
	if (path)
		old_pwd = ft_strdup(path);
	else
		old_pwd = ft_strdup("");
	if (!old_pwd)
		exit_failure(shell, "cd: oldpwd allocation");
	return (set_new_pwd(shell, old_pwd));
}

char	*get_cd_path(t_shell *shell, char *arg)
{
	char	*home;
	char	*oldpwd;

	if (!arg)
	{
		home = sh_get_env(shell->envp, "HOME");
		if (!home)
			return (print_cd_error(NULL, "HOME not set"), NULL);
		return (home);
	}
	if (ft_strcmp(arg, "-") == 0)
	{
		oldpwd = sh_get_env(shell->envp, "OLDPWD");
		if (!oldpwd)
			return (print_cd_error(NULL, "OLDPWD not set"), NULL);
		ft_putendl_fd(oldpwd, 1);
		return (oldpwd);
	}
	return (arg);
}

int	ft_cd(t_shell *shell, t_exec *exec_node)
{
	char	*path;

	path = get_cd_path(shell, exec_node->argv[1]);
	if (!path)
	{
		return (1);
	}
	if (chdir(path) != 0)
	{
		return (handle_chdir_error(path));
	}
	return (update_pwd_vars(shell));
}
