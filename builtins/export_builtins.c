/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/08/30 19:08:26 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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
				free(envpp->env[j]);
				envpp->env[j] = ft_strdup(new_var);
				updated_value = true;
			}
			j++;
		}
		if (!updated_value)
			update_environment(envpp, new_var);
	}
	return (false);
}

void	export_variable(char **args, t_redr *envpp)
{
	char	*equal_sign;
	char	*var_name;

	var_name = *args;
	if (!ft_isalpha_cha(var_name[0]) && var_name[0] != '_')
	{
		printf("export: %c: not a valid identifier\n", var_name[0]);
		return ;
	}
	equal_sign = ft_strchr(var_name, '=');
	printf("equal_sign : %s\n", equal_sign);
	printf("var_name : %s\n", var_name);
	if (equal_sign != NULL)
		update_or_add_variable(envpp, var_name);
	else
	{
		if (ft_strcmp(var_name, "=") > 0)
			update_environment(envpp, var_name);
	}
}

void	print_export(t_redr *direction)
{
	char	**env;
	int		i;
	int		j;

	env = direction->env;
	i = 0;
	while (env[i] != NULL)
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
			export_variable(&args[1], direction);
	}
	return (EXIT_SUCCESS);
}
