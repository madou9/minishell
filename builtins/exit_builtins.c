/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:04 by ihama             #+#    #+#             */
/*   Updated: 2023/08/31 21:51:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_exit_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	execute_exit(char **args)
{
	int		exit_code;

	exit_code = 0;
	if (args[0])
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (args[1])
	{
		if (args[2])
		{
			ft_putstr_fd("Error: Too many argument\n", STDERR_FILENO);
			return (false);
		}
		if (!ft_exit_number(args[1]))
		{
			ft_putstr_fd("Error: Numerique argument required \n", STDERR_FILENO);
			return (false);
		}
		exit_code = ft_atoi(*args);
		exit(exit_code);
	}
	exit(0);
}
