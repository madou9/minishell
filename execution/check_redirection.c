/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:31:11 by ihama             #+#    #+#             */
/*   Updated: 2023/08/25 16:38:05 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	output_redirection_append(char **args)
{
	int		fd;
	int		i;

	i = 0;

	if (ft_strncmp(args[i] , '>', 1) == 0)
	// If args[i] is ">", args[i + 1] will be the filename
		fd = open(args[i + 1],
				O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (ft_strncmp(args[i], '>>', 2) == 0)
        // If args[i] is ">>", args[i + 1] will also be the filename
		fd = open(args[i + 1],
				O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_fd("Error: failed to open output file\n", STDERR_FILENO);
	return (fd);
}

int	output_redirection(char *outfile)
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
}

int	check_redirection(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (strncmp(args[i], '<', 1) == 0 || ft_strncmp(args[i], '<<', 2) == 0)
		{
			if (input_redirection(args[i + 1]))
				return (EXIT_FAILURE);
			i += 2;
		}
		else if (ft_trncmp(args[i], '>', 1) == 0
			|| ft_strncmp(args[i], '>>', 2) == 0)
		{
			if (output_redirection(args[i + 1]))
				return (EXIT_FAILURE);
			i += 2;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
