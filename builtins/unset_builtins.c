/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:39:47 by ihama             #+#    #+#             */
/*   Updated: 2023/09/14 23:57:25 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*When a match is found (inside the if block), the inner loop
(controlled by j) starts from the index i and goes through the
remaining elements in the array. It shifts each element by overwriting
it with the next element, effectively removing the variable.
To remove an element from an array and shift the remaining elements, you should use envpp[j] = envpp[j + 1]
not envpp[j + 0]*/

void	free_environment(char **envpp)
{
	int	i;

	i = 0;
	while (envpp[i] != NULL)
	{
		free(envpp[i]);
		i++;
	}
	free(envpp);
}

bool	remove_variable(char **envpp, const char *var)
{
	int	i;
	int	j;

	i = 0;
	while (envpp[i] != NULL)
	{
		if (ft_strncmp(envpp[i], var, ft_strlen(var)) == 0)
		{
			j = i;
			// Remove this variable by shifting the array
			while (envpp[j] != NULL)
			{
				envpp[j] = envpp[j + 1];
				j++;
			}
			return (true);
		}
		i++;
	}
	return (false);
}

int	is_token_valid_unset(char *token)
{
	return (ft_strchr(token, '=')
		|| ft_strchr(token, '$')
		|| ft_strchr(token, '"')
		|| ft_strchr(token, '/')
		|| ft_isdigit(*token));
}

int	execute_unset(t_data *data, t_main *main)
{
	int		i;
	char	*error;

	i = 1;
	while (data->cmd[i] != NULL)
	{
		if (!is_valid_identifier(data->cmd[i]))
		{
			error = ft_strjoin("Error:unset is not valid identify.\n", data->cmd[i]);
			return (perror(error), free(error), -1);
		}
			// ft_printf("Error:unset %s is not valid identify.\n", data->cmd[i]);
		else if (!remove_variable(main->env, data->cmd[i]))
		{
			error = ft_strjoin("Error: Variable %s not found.\n", data->cmd[i]);
			return (perror(error), free(error), -1);
		}
		// ft_printf("Error: Variable %s not found.\n", data->cmd[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
