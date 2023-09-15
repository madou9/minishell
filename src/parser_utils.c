/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:34:21 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:44 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_procs(t_mylist *list)
{
	t_mylist	*head;
	int			i;

	i = 0;
	head = list;
	while (1)
	{
		if (head->type == PIPE)
			i++;
		if (!head->next)
			break ;
		head = head->next;
	}
	return (++i);
}
