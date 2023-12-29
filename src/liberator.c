/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:38:50 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/20 01:43:01 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_data(t_main *main)
{
	int		i;
	char	**temp;

	i = 0;
	while (i < main->procs)
	{	
		temp = main->data[i].cmd;
		while (*(main->data[i].cmd))
		{
			free(*(main->data[i].cmd));
			(main->data[i].cmd)++;
		}
		free(temp);
		i++;
	}
}

void	free_child_process(t_main *main)
{
	char	**temp;

	free_data(main);
	free(main->data);
	parser_free(main);
	if (main->pid)
		free(main->pid);
	if (main->procs > 1)
		free(main->pipes);
	temp = main->env;
	while (*(main->env))
	{
		free(*(main->env));
		main->env++;
	}
	free(temp);
}

void	free_main_process(t_main *main)
{
	free_data(main);
	free(main->data);
	parser_free(main);
	if (main->procs > 1)
		free(main->pid);
	if (main->procs > 1)
		free(main->pipes);
}

void	rm_tmp_files(int num, t_main *main)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (main->list->value && ft_strncmp("heredoc_tmp_",
				main->list->value, 12) == 0)
		{
			unlink(main->list->value);
			i++;
		}
		if (main->list->next == NULL)
			break ;
		main->list = main->list->next;
	}
}
