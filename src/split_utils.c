/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:02:18 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 23:29:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	skip_chars(char *str, int *i, int *j)
{
	while (str[*i] == ' ')
	{	
		*i += 1;
		*j += 1;
	}
	while (str[*i] != '\0' && str[*i] != ' ')
	{
		if (str[*i] == '\"')
		{
			*i += 1;
			while (str[*i] != '\"')
				*i += 1;
			*i += 1;
		}
		else if (str[*i] == '\'')
		{
			*i += 1;
			while (str[*i] != '\'')
				*i += 1;
			*i += 1;
		}
		else
			*i += 1;
	}
}

void	free_old_list(t_mylist *list)
{
	t_mylist	*head;
	t_mylist	*temp;

	head = list;
	while (1)
	{
		temp = head;
		head = head->next;
		if (temp->value)
			free(temp->value);
		free(temp);
		if (head == NULL)
			break ;
	}
}

void	list_iter(t_mylist **list, t_mylist *node)
{
	t_mylist	*head;

	if (!(*list))
		*list = node;
	else
	{
		head = *list;
		while (head->next != NULL)
			head = head->next;
		head->next = node;
	}
}
