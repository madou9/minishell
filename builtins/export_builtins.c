/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:40:25 by ihama             #+#    #+#             */
/*   Updated: 2023/09/01 15:41:38 by ihama            ###   ########.fr       */
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

// bool	is_export_valid(char *valu)
// {
// 	int	i;

// 	i = 0;
// 	if (!ft_isalpha_cha(*valu) && *valu != '_')
// 		printf("export: %c: not a valid identifier\n", valu[i]);
// 	while (valu[i])
// 	{
// 		if (valu[i] == '=' || (valu[i] == '+' && valu[i + 1] == '='))
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

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

void	export_variable(char **args, t_redr *envpp)
{
	int		i;
	char	*var_name;
	char	*equal_sign;

	i = 0;
	while (args[i])
	{
		var_name = args[i];
		equal_sign = ft_strchr(var_name, '=');
		if (equal_sign == var_name)
		{
			printf("export: %s: not a valid identifier\n", var_name);
			return ;
		}
		if (!is_valid_identifier(var_name))
		{
			printf("export: %s: not a valid identifier\n", var_name);
			return ;
		}
		if (equal_sign != NULL)
			update_or_add_variable(envpp, var_name);
		else
			update_environment(envpp, var_name);
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
