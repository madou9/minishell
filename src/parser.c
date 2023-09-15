/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:15:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/14 02:18:42 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parser_free(t_main *main)
{
	t_mylist	*node;
	t_mylist	*temp;

	node = main->list;
	while (1)
	{
		if (node->value)
			free(node->value);
		if (node)
		{
			temp = node->next;
			free(node);
		}
		node = temp;
		if (node == NULL)
			break ;
	}	
}

void	fix_types(t_main *main)
{
	t_mylist	*head;

	head = main->list;
	while (1)
	{
		if (head->type == LS || head->type == LSLS
			|| head->type == GRT || head->type == GRTGRT)
		{
			if (head->next && (head->next->type == WRD
					|| head->next->type == WRD_QUOTED))
				head->next->type = WRD_REDIR;
			else if (head->type == WRD_REDIR)
				head->next->type = HEREDOC_QUOT;
		}
		else if (head->type == WRD || head->type == WRD_QUOTED)
			head->type = WRD_CMD;
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}

void	init_data(t_main *main)
{
	int	count;
	int	i;

	count = count_procs(main->list);
	i = 0;
	main->data = malloc(sizeof(t_data) * count);
	while (i < count)
	{
		main->data[i].fd[0] = 0;
		main->data[i].fd[1] = 1;
		main->data[i].index = i;
		i++;
	}
	main->procs = count;
	fix_types(main);
}

int	parser(t_main *main)
{
	init_data(main);
	if (parse_redir(main) != 0)
		return (parser_free(main), -1);
	parse_command(main);
	parser_free(main);
	return (0);
}
