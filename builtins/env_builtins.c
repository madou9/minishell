/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:38:38 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 23:56:28 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	execute_env(t_main *main)
{
	int	i;

	i = 0;
	while (main->env[i])
	{
		if (ft_strchr(main->env[i], '='))
		{
			ft_putstr_fd(main->env[i], STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
