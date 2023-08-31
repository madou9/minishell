/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:11:50 by ihama             #+#    #+#             */
/*   Updated: 2023/08/30 19:16:28 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	update_environment(t_redr *direction, char *new_var)
{
	int		env_count;
	int		i;
	char	**new_env;

	env_count = 0;
	while (direction->env[env_count] != NULL)
		env_count++;
	new_env = ft_calloc(sizeof(char *), (env_count + 2));
	if (!new_env)
		return ;
	i = 0;
	while (i < env_count)
	{
		new_env[i] = direction->env[i];
		i++;
	}
	free(direction->env);
	new_env[env_count] = new_var;
	new_env[env_count + 1] = NULL;
	direction->env = new_env;
}
