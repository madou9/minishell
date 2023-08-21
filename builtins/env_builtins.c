/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:38:38 by ihama             #+#    #+#             */
/*   Updated: 2023/08/20 17:06:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	execute_env(t_redr *tmp)
{
	int	i;

	i = 0;
	while (tmp->env[i])
	{
		ft_putstr_fd(tmp->env[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
