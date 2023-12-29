/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:25:59 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 23:12:01 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	join_nodes(t_mylist *lst, t_explst **list)
{
	t_explst	*node;
	char		*new;
	char		*temp;

	node = *list;
	new = NULL;
	while (1)
	{
		temp = new;
		new = ft_strjoin(temp, node->str);
		if (node->str)
			free(node->str);
		if (temp)
			free(temp);
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	temp = lst->value;
	lst->value = new;
	free(temp);
}

char	*expand_var(char *var, char **env)
{
	int		i;
	int		j;
	char	*value;
	char	*temp;

	j = 0;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '=')
			break ;
		else
			i++;
	}
	free(var);
	if (env[i] != NULL)
	{
		temp = ft_strchr(env[i], '=');
		temp++;
		value = ft_substr(temp, 0, ft_strlen(temp));
		return (value);
	}
	return (NULL);
}

void	expand(char *str, t_main *main, int *i, t_explst *node)
{
	int		j;
	char	*var_name;

	j = 0;
	*i = *i + 1;
	if (str[*i] == '?' && str[*i - 1] == '$')
		expand_err(node, i);
	else
	{	
		while (str[*i] != '\0' && (ft_isalnum(str[*i]) || str[*i] == '_'))
		{	
			j++;
			*i += 1;
		}
		if (j > 0)
		{
			var_name = ft_substr(&str[*i - j], 0, j);
			node->str = expand_var(var_name, main->env);
		}
		else
			node->str = ft_strdup("$");
	}
}

t_explst	*check_expansions(t_main *main, t_mylist *lst,
	t_explst *node)
{
	int			i;
	int			j;
	t_explst	*list;

	i = 0;
	j = 0;
	list = NULL;
	while (lst->value[i] != '\0')
	{
		node = new_node(&list);
		skip_char(lst->value, &j, &i);
		if (j > 0)
		{
			node->str = ft_substr(lst->value, i - j, j);
			j = 0;
		}
		else if (lst->value[i] == '$')
			expand(lst->value, main, &i, node);
	}
	return (list);
}

void	expand_tokens(t_main *main)
{
	t_mylist	*head;
	t_explst	*temp_list;
	t_explst	*temp_node;

	head = main->list;
	temp_list = NULL;
	temp_node = NULL;
	while (1)
	{
		if (head->type == WRD || head->type == WRD_QUOTED)
		{
			temp_list = check_expansions(main, head, temp_node);
			if (temp_list != NULL)
				join_nodes(head, &temp_list);
			if (temp_node)
				free(temp_node);
			if (temp_list)
				free(temp_list);
		}
		is_heredoc(head);
		if (head->next == NULL)
			break ;
		head = head->next;
	}
}
