/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:29:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/20 01:32:56 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_mylist	*create_redir_node(int type, char *str)
{
	t_mylist	*node;

	node = malloc(sizeof(t_mylist));
	node->type = type;
	if (str)
		node->value = ft_substr(str, 0, ft_strlen(str));
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
}

t_mylist	*new_split_node(int start, int end, char *str)
{
	t_mylist	*node;

	node = malloc(sizeof(t_mylist));
	if (ft_strchr(str, '\"') == 0 && ft_strchr(str, '\'') == 0)
		node->type = WRD;
	else
		node->type = WRD_QUOTED;
	node->value = ft_substr(str, start, end - start);
	node->next = NULL;
	return (node);
}

t_mylist	*split_str(char *str)
{
	t_mylist	*list;
	t_mylist	*node;
	int			j;
	int			i;

	list = NULL;
	i = 0;
	j = 0;
	while (str != NULL && str[i] != '\0')
	{
		skip_chars(str, &i, &j);
		node = new_split_node(j, i, str);
		j = i;
		list_iter(&list, node);
	}
	return (list);
}

void	postsplit(t_main *main)
{
	t_mylist	*head;
	t_mylist	*temp;
	t_mylist	*temp_list;

	head = main->list;
	temp_list = NULL;
	temp = NULL;
	while (1)
	{
		if ((head->type == WRD || head->type == WRD_QUOTED)
			&& head->value != NULL)
			c1(&temp_list, &temp, &head);
		else
			c2(&temp_list, &temp, &head);
		if (!head->next)
			break ;
		head = head->next;
	}
	free_old_list(main->list);
	main->list = temp_list;
	remove_quotes(main->list);
}
