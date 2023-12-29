/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:17:18 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 22:29:30 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	syntax_error(int type)
{
	g_error_code = 258;
	if (type == LS)
		printf("minishell: syntax error near unexpected token `<'\n");
	else if (type == LSLS)
		printf("minishell: syntax error near unexpected token `<<'\n");
	else if (type == GRT)
		printf("minishell: syntax error near unexpected token `>'\n");
	else if (type == GRTGRT)
		printf("minishell: syntax error near unexpected token `>>'\n");
	else if (type == -1)
		printf("minishell: syntax error near unexpected token `newLine'\n");
	else if (type == PIPE)
		printf("minishell: syntax error near unexpected token `|'\n");
}

int	check_pipe(t_mylist *head, t_main *main, int *i)
{
	if (head->type == PIPE)
	{
		if ((head->next && head->next->type == PIPE)
			|| !head->next || main->list->type == PIPE)
			return (syntax_error(PIPE), 0);
		else
			*i += 1;
	}
	return (1);
}

int	check_redir(t_mylist *head, int *i)
{
	(void) i;
	if (head->type == LS || head->type == GRT
		|| head->type == GRTGRT)
	{
		if ((head->next && head->next->type != WRD_REDIR) || !head->next)
			return (syntax_error(head->type), 0);
	}
	return (1);
}

int	check_heredoc(t_mylist *head, t_main *main, int *i)
{	
	if (head->type == LSLS)
	{
		if (head->next && (head->next->type == WRD_REDIR
				|| head->next->type == HEREDOC_QUOT))
			heredoc(head, main, i);
		else
			return (syntax_error(head->type), 0);
	}
	return (1);
}

int	parse_redir(t_main *main)
{
	t_mylist	*head;
	int			i;

	i = 0;
	main->heredocs = 0;
	head = main->list;
	while (1)
	{
		if (!check_pipe(head, main, &i) || !check_redir(head, &i)
			|| !check_heredoc(head, main, &main->heredocs))
			return (g_error_code = 1, free(main->data), -1);
		if (!head->next)
			break ;
		head = head->next;
	}
	return (0);
}
