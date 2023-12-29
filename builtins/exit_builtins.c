/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:04 by ihama             #+#    #+#             */
/*   Updated: 2023/09/19 23:48:12 by voszadcs         ###   ########.fr       */
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

int	execute_exit(t_data *data)
{
	if (data->cmd[0])
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (data->cmd[1])
	{
		if (data->cmd[2])
		{
			ft_putstr_fd("Error: Too many argument\n", STDERR_FILENO);
			return (false);
		}
		if (!ft_exit_number(data->cmd[1]))
		{
			ft_putstr_fd("Error: Numerique argument required \n", STDERR_FILENO);
			return (false);
		}
	}
	if (data->cmd[1] && *data->cmd[1])
		g_error_code = ft_atoi(data->cmd[1]);
	exit(g_error_code);
}
