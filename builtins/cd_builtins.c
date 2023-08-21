/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:43 by ihama             #+#    #+#             */
/*   Updated: 2023/08/19 19:41:32 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// int	change(char *path, int home)
// {
// 	char	*pwd;

// 	pwd = getcwd(NULL, 0);
// 	if (!chdir(path))
// 	{
// 		if (pwd)
// 		{
// 			set_env("OLDPWD", pwd);
// 			free(pwd);
// 		}
// 		if ((pwd = getcwd(NULL, 0)))
// 		{
// 			set_env("PWD", pwd);
// 			free(pwd);
// 		}
// 		if (home)
// 			free(path);
// 		return (1);
// 	}
// 	free(pwd);
// 	return (0);
// }

char	*get_env(const char *str, t_input *input)
{
	size_t	str_len;
	int		i;

	str_len = ft_strlen(str);
	i = 0;
	while (input->redirections->env[i])
	{
		if (!strncmp(input->redirections->env[i], str, str_len))
			return (strdup(input->redirections->env[i] + str_len));
		i++;
	}
	return (NULL);
}

int	execute_cd(t_input *input, char *direction)
{
	char		**args;
	const char	*home_dir;
	const char	*old_pwd;

	args = input->str;
	if (args[1] == NULL)
	{
		home_dir = ft_getenv(direction, "HOME=");
		if (!home_dir)
			ft_putstr_fd("Error: HOME not set \n", STDERR_FILENO);
		if (chdir(home_dir) == -1)
			ft_putstr_fd("Error: cd cannot change directory", STDERR_FILENO);
	}
	else if (strcmp(args[1], "-") == 0)
	{		
		old_pwd = getcwd("OLDPWD\n", 7);
		if (!old_pwd)
			ft_putstr_fd("Error: OLDPWD not set\n", STDERR_FILENO);
		if (chdir(old_pwd) == -1)
			ft_putstr_fd("Error: can't OLDPWD\n", STDERR_FILENO);
	}
	return (update_pwd());
}
