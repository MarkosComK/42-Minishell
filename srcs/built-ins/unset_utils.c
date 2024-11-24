/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:03:40 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/11/24 14:25:37 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

void	print_invalid_identifier(char *arg, char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	exit_code(1);
}

void	remove_env_var(t_shell *shell, const char *var_name)
{
	t_list	*prev;

	if (check_first_node(shell, var_name))
		return ;
	prev = find_prev_node(shell->envp, var_name);
	if (prev)
		remove_node(prev);
}

int	is_exact_var(t_env *env_var, const char *var_name)
{
	char	*plus;
	char	*equals_var;
	char	*equals_env;
	size_t	len_name;
	size_t	len_env;

	plus = ft_strnstr(var_name, "+=", ft_strlen(var_name));
	equals_var = ft_strchr(var_name, '=');
	equals_env = ft_strchr(env_var->value, '=');
	if (plus)
		len_name = plus - var_name;
	else if (equals_var)
		len_name = equals_var - var_name;
	else
		len_name = ft_strlen(var_name);
	if (equals_env)
		len_env = equals_env - env_var->value;
	else
		len_env = ft_strlen(env_var->value);
	if (len_name != len_env)
		return (0);
	return (ft_strncmp(env_var->value, var_name, len_name) == 0);
}
