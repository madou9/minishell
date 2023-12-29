/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:27:21 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 23:18:11 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_pipes(t_main *main)
{
	int	i;

	i = 0;
	main->pipes = malloc(sizeof(t_pipes) * (main->procs - 1));
	while (i < (main->procs - 1))
	{
		pipe(main->pipes[i].pipe);
		i++;
	}
}

void	do_pipes(t_pipes *pipes, int ind, int procs)
{
	if (ind == 0)
	{
		dup2(pipes[ind].pipe[1], STDOUT_FILENO);
	}
	else if (ind == (procs - 1))
	{
		dup2(pipes[ind - 1].pipe[0], STDIN_FILENO);
	}
	else
	{
		dup2(pipes[ind - 1].pipe[0], STDIN_FILENO);
		dup2(pipes[ind].pipe[1], STDOUT_FILENO);
	}
}

void	close_all_pipes(t_main *main)
{
	int	i;

	i = 0;
	while (i < (main->procs - 1))
	{
		close(main->pipes[i].pipe[0]);
		close(main->pipes[i].pipe[1]);
		i++;
	}
}
