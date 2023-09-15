/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:37:57 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 18:25:34 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execute_pwd(char **argv)
{
	char	*pwdir;

	(void)argv;
	pwdir = getcwd(NULL, 0);
	if (pwdir == NULL)
		ft_putstr_fd("Error: Unable to get current working directory\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd(pwdir, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		free(pwdir);
	}
}
