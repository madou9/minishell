/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 23:57:05 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

bool	update_or_add_variable(t_main *main, char *new_var)
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
		while (main->env[j] != NULL)
		{
			if (ft_strncmp(main->env[j], new_var, value - new_var) == 0)
			{
				free(main->env[j]);
				main->env[j] = ft_strdup(new_var);
				updated_value = true;
			}
			j++;
		}
		if (!updated_value)
			update_environment(main, new_var);
	}
	return (false);
}

bool	is_valid_identifier(const char *name)
{
	int	j;

	j = 0;
	while (name[j] != '\0' && name[j] != '=')
	{
		if (!ft_isalnum(name[j]) && name[j] != '_')
			return (false);
		j++;
	}
	return (true);
}

void	export_variable(char **args, t_main *main)
{
	int		i;
	char	*var_name;
	char	*equal_sign;

	i = 0;
	while (args[i])
	{
		var_name = args[i];
		equal_sign = ft_strchr(var_name, '=');
		if (ft_strncmp(var_name, "_=", 2) == 0)
			return ;
		if (!is_valid_identifier(var_name) || equal_sign == var_name)
		{
			printf("Error: %s: not a valid identifier\n", var_name);
			return ;
		}
		if (equal_sign)
			update_or_add_variable(main, var_name);
		else
			update_environment(main, var_name);
		i++;
	}
}

void	print_export(t_main *main)
{
	char	**env;
	int		i;
	int		j;

	env = main->env;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "_=", 2) != 0)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			j = 0;
			while (env[i][j] != '=' && env[i][j] != '\0')
			{
				ft_putchar_fd(env[i][j], STDOUT_FILENO);
				j++;
			}
			if (env[i][j] != '\0')
				printf("=\"%s\"\n", &env[i][j + 1]);
			else
				printf("%s\n", &env[i][j]);
		}
		i++;
	}
}

void	execute_export(t_data *data, t_main *main)
{
	if (data->cmd[1] == NULL)
		print_export(main);
	else
	{
		if (data->cmd[1] != NULL)
			export_variable(&data->cmd[1], main);
	}
}
