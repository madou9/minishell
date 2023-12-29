/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:40:11 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 23:10:45 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_args(t_mylist *head)
{
	int	count;

	count = 0;
	while (1)
	{
		if (head->value && (head->type == WRD_CMD \
			|| head->type == WRD_SINGLE_Q))
			count++;
		if (!head->next || head->next->type == PIPE)
			break ;
		head = head->next;
	}
	return (count);
}

void	join_args(t_mylist *head, char **cmd)
{
	while (head->type != PIPE)
	{
		if (head->value && (head->type == WRD_CMD
				|| head->type == WRD_SINGLE_Q))
		{
			*cmd = malloc(sizeof(char) * (ft_strlen(head->value) + 1));
			*cmd = ft_substr(head->value, 0, ft_strlen(head->value));
			cmd++;
		}
		if (!head->next)
			break ;
		head = head->next;
	}
}

void	parse_command(t_main *main)
{
	t_mylist	*head;
	int			i;
	int			count;

	i = 0;
	head = main->list;
	while (i < main->procs && head)
	{
		count = count_args(head);
		main->data[i].cmd = malloc(sizeof(char *) * (count + 1));
		main->data[i].cmd[count] = NULL;
		join_args(head, main->data[i].cmd);
		while (head->next)
		{
			head = head->next;
			if (head->type == PIPE)
			{	
				head = head->next;
				break ;
			}
		}
		i++;
	}
	i = 0;
}
