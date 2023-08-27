/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:31:11 by ihama             #+#    #+#             */
/*   Updated: 2023/08/27 14:25:14 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	input_redirection(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
	free(infile);
	if (fd == -1)
	{
		ft_putstr_fd("Error: failed to open input file\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		ft_putstr_fd("Error:dup2 for input redirection failed\n", STDERR_FILENO);
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	output_redirection_append(char **args)
{
	int	fd;
	int	i;

	fd = -2;
	i = 0;
	if (ft_strcmp(args[i], ">") == 0)
		fd = open(args[i + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (ft_strcmp(args[i], ">>") == 0)
		fd = open(args[i + 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_fd("Error: failed to open output file\n", STDERR_FILENO);
	return (fd);
}

int	output_redirection(char **outfile)
{
	int	fd;

	fd = output_redirection_append(outfile);
	if (fd == -1)
	{
		ft_putstr_fd("Error: failed to open output file\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error:dup2 for output redirection failed\n", STDERR_FILENO);
		close(fd);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_redirection(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], "<") == 0 || ft_strcmp(args[i], "<<") == 0)
		{
			if (input_redirection(args[i + 1]))
				return (EXIT_FAILURE);
			i += 2;
		}
		else if (ft_strcmp(args[i], ">") == 0
			|| ft_strcmp(args[i], ">>") == 0)
		{
			if (output_redirection(&args[i]))
				return (EXIT_FAILURE);
			i += 2;
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

// execve("fullpath", ["echo", ">", "file", NULL], env);

// execve("/bin/cat", ["cat", NULL, "file", NULL], env);

