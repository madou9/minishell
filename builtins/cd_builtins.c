/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:43 by ihama             #+#    #+#             */
/*   Updated: 2023/08/30 19:05:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	old_pwd(char **args, t_redr *direction)
{
	char		*update_oldpwd;
	char		*update_pwd;
	char		*pwd;

	if (strncmp(args[1], "-", 1) == 0)
	{		
		pwd = getcwd(NULL, 0);
		if (!pwd)
			ft_putstr_fd("Error: OLDPWD not set\n", STDERR_FILENO);
		update_oldpwd = ft_getenv(direction->env, "OLDPWD");
		if (chdir(update_oldpwd) == -1)
			ft_putstr_fd("Error: can't OLDPWD\n", STDERR_FILENO);
		update_pwd = ft_strjoin("PWD=", pwd);
		update_or_add_variable(direction, update_pwd);
	}
	return (EXIT_SUCCESS);
}

int	execute_cd(char **args, t_redr *direction)
{
	if (args[1] == NULL)
		home_case(args, direction);
	else if (ft_strncmp(args[1], "-", 1) == 0)
		old_pwd(args, direction);
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(args[1], STDERR_FILENO);
		}
	}
	return (EXIT_SUCCESS);
}

int	home_case(char **args, t_redr *env)
{
	char	*home_dir;
	char	*update_pwd;

	if (args[1] == NULL)
	{
		home_dir = ft_getenv(env->env, "HOME");
		if (chdir(home_dir) == -1)
			ft_putstr_fd("Error: cd cannot change directory\n", STDERR_FILENO);
		update_pwd = ft_strjoin("PWD=", home_dir);
		update_or_add_variable(env, update_pwd);
	}
	return (0);
}
