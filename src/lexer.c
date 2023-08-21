/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:45:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/16 22:00:17 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	tokenize(char *str, t_mylist *list)
{
	int	i;
	int start;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '<' && str[i + 1] != '<')
		return (list->type = LS, list->value = NULL, i + 1);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (list->type = LSLS, list->value = NULL, i + 2);
	else if (str[i] == '>' && str[i + 1] != '>')
		return (list->type = GRT, list->value = NULL, i + 1);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (list->type = GRTGRT, list->value = NULL, i + 2);
	else if (str[i] == '|')
		return (list->type = PIPE, list->value = NULL, i + 1);
	else
	{
		start = i;
		if (str[i] == '\0')
			return (list->type = -1, i);
		while (str[i] != '\0' && str[i] != ' ')
			i++;
		return (list->type = WRD, list->value = ft_substr(str, start, i - start), i);
	}
}

void	fill_list(t_mylist	**list, char *str, int *index)
{
	t_mylist	*node;
	t_mylist	*head;
	int			i;

	i = 0;
		node = malloc (sizeof(t_mylist));
	if (node == NULL)
		exit(0);//_error(ERR_MALLOC);
	node->next = NULL;
	i = tokenize(&str[*index], node);
	if (*list == NULL)
		*list = node;
	else
	{
		head = *list;
		while (head->next != NULL)
			head = head->next;
		if (node->type != -1)
			head->next = node;
	}
	*index = *index + i;
}

t_mylist	*lexer(char *str)
{
	t_mylist	*list;
	char		*current;
	int			index;

	list = NULL;
	current = str;
	index = 0;
	while (current[index] != '\0')
		fill_list(&list, current, &index);
	return (list);
}
