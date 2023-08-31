/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:31:11 by ihama             #+#    #+#             */
/*   Updated: 2023/08/31 15:07:12 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	input_redirection(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY, 0777);
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

int	output_redirection_append(char *outfile)
{
	int	output_fd;

	output_fd = open(outfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (output_fd == -1)
		perror("Error: failed to open output file");
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error:dup2 for input redirection failed\n", STDERR_FILENO);
		close(output_fd);
		return (EXIT_FAILURE);
	}
	close(output_fd);
	return (EXIT_SUCCESS);
}

int	output_redirection_truncate(char *outfile)
{
	int	input_fd;

	input_fd = open(outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (input_fd == -1)
		perror("Error: failed to open output file");
	if (dup2(input_fd, STDOUT_FILENO) == -1)
	{
		ft_putstr_fd("Error:dup2 for input redirection failed\n", STDERR_FILENO);
		close(input_fd);
		return (EXIT_FAILURE);
	}
	close(input_fd);
	return (EXIT_SUCCESS);
}

int	output_redirection(char **args)
{
	int	i;

	i = 0;
	if (args[i] != NULL)
	{
		if (ft_strcmp(args[i], ">") == 0)
			return (output_redirection_truncate(args[i + 1]));
		else if (ft_strcmp(args[i], ">>") == 0)
			return (output_redirection_append(args[i + 1]));
	}
	return (-1);
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
			{
				return (EXIT_FAILURE);
			}
			args[i] = NULL;
			i += 2;
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

// execve("fullpath", ["echo", ">", "file", NULL], env);

// execve("/bin/cat", ["cat", NULL, "file", NULL], env);

