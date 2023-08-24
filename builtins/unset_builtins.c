/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:39:47 by ihama             #+#    #+#             */
/*   Updated: 2023/08/23 11:48:46 by ihama            ###   ########.fr       */
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
		if (strncmp(envpp[i], var, ft_strlen(var)) == 0)
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

int	execute_unset(char **args, t_redr *envpp)
{
	int i;

	i = 1; // Start from index 1 to skip the command name "unset"
	while (args[i] != NULL)
	{
		if (!remove_variable(envpp->env, args[i]))
			fprintf(stderr, "Error: Variable %s not found.\n", args[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
