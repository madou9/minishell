/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:28:29 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 23:11:46 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	skip_char(char *str, int *j, int *i)
{
	while (str[*i] != '$' && str[*i] != '\0')
	{
		if (str[*i] == '\'')
		{
			*i += 1;
			*j += 1;
			while (str[*i] != '\'')
			{
				*i += 1;
				*j += 1;
			}
		}
		*j += 1;
		*i += 1;
	}
}

t_explst	*new_node(t_explst **list)
{
	t_explst	*head;
	t_explst	*node;

	node = malloc(sizeof(t_explst));
	node->next = NULL;
	node->str = NULL;
	if (*list == NULL)
		*list = node;
	else
	{
		head = *list;
		while (1)
		{	
			if (head->next == NULL)
				break ;
			head = head->next;
		}
		head->next = node;
	}
	return (node);
}

void	is_heredoc(t_mylist *node)
{
	if (node->type == LSLS && node->next
		&& node->next->type == WRD_QUOTED)
		node->next->type = WRD_REDIR;
}

void	expand_err(t_explst *node, int *i)
{		
	node->str = ft_substr(ft_itoa(g_error_code), 0,
			ft_strlen(ft_itoa(g_error_code)));
	*i = *i + 1;
}
