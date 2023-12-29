/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:38:54 by ihama             #+#    #+#             */
/*   Updated: 2023/09/19 22:52:47 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_args(char **args, int fd)
{
	int		i;

	i = 0;
	while (args[i])
	{
		write(fd, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
}

int	ft_repeat_str(char repeat, char *str, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] != repeat)
			return (0);
		i++;
	}
	return (1);
}

int	execute_echo(t_data *data)
{
	bool	escape_newline;
	int		i;

	i = 1;
	escape_newline = true;
	while (data->cmd[i] && data->cmd[i][0] == '-'
		&& ft_repeat_str('n', data->cmd[i], 1))
	{
			escape_newline = false;
			i++;
	}
	print_args(data->cmd + i, STDOUT_FILENO);
	if (escape_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
