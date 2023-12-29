/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:11:50 by ihama             #+#    #+#             */
/*   Updated: 2023/09/20 01:25:31 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	update_environment( t_main *main, char *new_var)
{
	int		env_count;
	int		i;
	char	**new_env;

	env_count = 0;
	while (main->env[env_count] != NULL)
		env_count++;
	new_env = ft_calloc(sizeof(char *), (env_count + 2));
	if (!new_env)
		return ;
	i = 0;
	while (i < env_count)
	{
		new_env[i] = main->env[i];
		i++;
	}
	free(main->env);
	new_env[env_count] = ft_substr(new_var, 0, ft_strlen(new_var));
	new_env[env_count + 1] = NULL;
	main->env = new_env;
}
