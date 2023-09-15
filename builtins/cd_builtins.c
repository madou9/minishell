/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:43 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 23:55:33 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	old_pwd(t_data *data,  t_main *main)
{
	char		*update_oldpwd;
	char		*update_pwd;
	char		*pwd;

	if (ft_strncmp(data->cmd[1], "-", 1) == 0)
	{		
		pwd = getcwd(NULL, 0);
		if (!pwd)
			ft_putstr_fd("Error: OLDPWD not set\n", STDERR_FILENO);
		update_oldpwd = ft_getenv(main->env, "OLDPWD");
		if (chdir(update_oldpwd) == -1)
			ft_putstr_fd("Error: can't OLDPWD\n", STDERR_FILENO);
		update_pwd = ft_strjoin("PWD=", pwd);
		update_or_add_variable(main, update_pwd);
	}
	return (EXIT_SUCCESS);
}

int	execute_cd(t_data *data, t_main *main)
{
	if (data->cmd[1] == NULL)
		home_case(data, main);
	else if (ft_strncmp(data->cmd[1], "-", 1) == 0)
		old_pwd(data, main);
	else
	{
		if (chdir(data->cmd[1]) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(data->cmd[1], STDERR_FILENO);
		}
	}
	return (EXIT_SUCCESS);
}

int	home_case(t_data *data, t_main *main)
{
	char	*home_dir;
	char	*update_pwd;

	if (data->cmd[1] == NULL)
	{
		home_dir = ft_getenv(main->env, "HOME");
		if (chdir(home_dir) == -1)
			ft_putstr_fd("Error: cd cannot change directory\n", STDERR_FILENO);
		update_pwd = ft_strjoin("PWD=", home_dir);
		update_or_add_variable(main, update_pwd);
	}
	return (0);
}
