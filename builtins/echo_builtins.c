/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:38:54 by ihama             #+#    #+#             */
/*   Updated: 2023/08/27 13:21:39 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

int	execute_echo(char **args)
{
	bool	escape_newline;

	escape_newline = false;
	while (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
	{
		escape_newline = true;
		args++;
	}
	print_args(args + 1);
	if (!escape_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
