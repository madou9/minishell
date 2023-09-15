/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:34:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/06 22:18:17 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	count_length_no_quotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			count--;
		i++;
		count++;
	}
	return (count);
}

char	*new_str(char *str, int count)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * (count + 1));
	temp[count] = '\0';
	count = 0;
	while (temp[count] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			i++;
		else
		{	
			temp[count] = str[i];
			count++;
			i++;
		}
	}
	return (temp);
}

void	remove_quotes(t_mylist *list)
{
	t_mylist	*head;
	char		*temp;

	head = list;
	while (1)
	{
		if (head->type == WRD_QUOTED)
		{
			temp = new_str(head->value, count_length_no_quotes(head->value));
			free(head->value);
			head->value = temp;
		}
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}
