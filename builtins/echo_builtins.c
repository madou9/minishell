/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:38:54 by ihama             #+#    #+#             */
/*   Updated: 2023/08/20 12:23:31 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_args(char **args)
{
	int		i;
	ssize_t	result;
	ssize_t	space_result;

	i = 0;
	while (args[i])
	{
		result = write(STDOUT_FILENO, args[i], ft_strlen(args[i]));
		if (result == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		if (args[i + 1])
		{
			space_result = write(STDOUT_FILENO, " ", 1);
			if (space_result == -1)
			{
				perror("write");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

int	execute_echo(char **args)
{
	bool	escape_newline;
	ssize_t	newline_result;

	escape_newline = false;
	while (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
	{
		escape_newline = true;
		args++;
	}
	print_args(args + 1);
	if (!escape_newline)
	{
		newline_result = write(STDOUT_FILENO, "\n", 1);
		if (newline_result == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
