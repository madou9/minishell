/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:01:04 by ihama             #+#    #+#             */
/*   Updated: 2023/08/20 13:28:48 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	execute_exit(char **args)
{
	int		exit_code;

	exit_code = 0;
	if (args[0])
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (args[1] && args[2])
		ft_putstr_fd("Error: Too many argument\n", STDERR_FILENO);
	if (args[0])
		exit_code = ft_atoi(args[1]);
	exit(exit_code);
}
