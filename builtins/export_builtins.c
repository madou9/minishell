/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/08/22 15:27:48 by ihama            ###   ########.fr       */
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
	new_env[env_count] = new_var;
	new_env[env_count + 1] = NULL;
	free(direction->env);
	direction->env = new_env;
}

bool	update_or_add_variable(t_redr *envpp, char *new_var)
{
	char	*value;
	int		j;
	bool	updated_value;

	value = ft_strchr(new_var, '=');
	if (value != NULL)
	{
		value++;
		updated_value = false;
		j = 0;
		while (envpp->env[j] != NULL)
		{
			if (strncmp(envpp->env[j], new_var, value - new_var) == 0)
			{
				envpp->env[j] = new_var;
				updated_value = true;
			}
			j++;
		}
		if (!updated_value)
			update_environment(envpp, new_var);
	}
	return (false);
}

void	update_export(char **args, t_redr *envpp)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (update_or_add_variable(envpp, args[i]))
			fprintf(stderr, "Error: Invalid variable format: %s\n", args[i]);
		i++;
	}
}

int	execute_export(char **args, t_redr *direction)
{
	int		i;

	i = 0;
	if (args[1] == NULL)
	{
		while (direction->env[i] != NULL)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(direction->env[i], STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			i++;
		}
	}
	else
	{
		if (args[i] != NULL)
			update_export(args, direction);
	}
	return (EXIT_SUCCESS);
}
