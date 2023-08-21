/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/08/21 21:54:35 by ihama            ###   ########.fr       */
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

bool	check_variable(t_redr *direc, char *var)
{
	int	i;

	i = 0;
	while (direc->env[i] != NULL)
	{
		if (strncmp(direc->env[i], var, ft_strlen(var)) == 0)
			return (true);
		i++;
	}
	return (false);
}

void	update_export(char **args, t_redr *envpp)
{
	int		i;
	char	*value;

	i = 0;
	while (args[i] != NULL)
	{
		value = ft_strchr(args[i], '=');
		if (value != NULL)
		{
			value++;
			if (!check_variable(envpp, args[i]))
				update_environment(envpp, args[i]);
			else
				fprintf(stderr, "Error: Variable %s already exists.\n", args[i]);
		}
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
