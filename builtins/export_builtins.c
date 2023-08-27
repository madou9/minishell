/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/08/27 22:26:51 by ihama            ###   ########.fr       */
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

bool	is_export_valid(char *valu)
{
	int	i;

	i = 0;
	if (!ft_isalpha_cha(*valu) && *valu != '_')
		printf("export: %c: not a valid identifier\n", valu[i]);
	while (valu[i])
	{
		if (valu[i] == '=' || (valu[i] == '+' && valu[i + 1] == '='))
			return (true);
		i++;
	}
	return (false);
}

void	update_export(char **args, t_redr *envpp)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (is_export_valid(args[i]))
			update_or_add_variable(envpp, args[i]);
		i++;
	}
}

void	print_export(t_redr *direction)
{
	char	**env;
	int		i;
	int		j;

	env = direction->env;
	i = 0;
	while (env[i] != NULL && ft_strchr(env[i], '='))
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		j = 0;
		while (env[i][j] != '=')
		{
			ft_putchar_fd(env[i][j], STDOUT_FILENO);
			j++;
		}
		printf("=\"%s\"\n", &env[i][j + 1]);
		i++;
	}
}

int	execute_export(char **args, t_redr *direction)
{
	if (args[1] == NULL)
		print_export(direction);
	else
	{
		if (args[1] != NULL)
			update_export(args, direction);
	}
	return (EXIT_SUCCESS);
}
