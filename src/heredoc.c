/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:49 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 22:29:30 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*cpy_no_quotes(char *src, char *new)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		if (*src != '\'' && *src != '\"')
		{
			new[i] = *src;
			i++;
			src++;
		}
		else
			src++;
	}
	return (new);
}

char	*rm_quotes(char *str, int *type)
{
	int		i;
	int		count;
	char	*temp;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
			count++;
		i++;
	}
	if (count == 0)
		return (str);
	*type = 20;
	temp = malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	temp[ft_strlen(str) - count] = '\0';
	return (cpy_no_quotes(str, temp));
}

char	*expand_rl(char *str, t_main *main)
{
	char	*temp;
	char	*temp_1;
	int		i;

	i = 0;
	temp = NULL;
	if (str[i] == '$' && str[i + 1] == '?')
	{
		temp = ft_substr(ft_itoa(g_error_code),
				0, ft_strlen(ft_itoa(g_error_code)));
		i++;
	}
	else if (str[i] == '$' && str[i + 1] == '$')
		i++;
	else if (str[i] == '$')
	{
		temp_1 = temp;
		temp = ft_strjoin(temp, get_var(str, i, main->env));
		if (temp_1)
			free(temp_1);
	}
	if (!temp)
		return (str);
	return (free(str), temp);
}

void	read_heredoc_input(char *name, t_mylist *node, t_main *main, int fd)
{
	char	*message;
	char	*delim;

	delim = rm_quotes(node->next->value, &node->next->type);
	while (1)
	{
		message = readline("> ");
		if ((ft_strncmp(message, delim, ft_strlen(message)) != 0))
		{	
			if (node->next->type != 20)
				message = expand_rl(message, main);
			ft_putstr_fd(message, fd);
			ft_putchar_fd('\n', fd);
		}
		else if (message[0] != '\0')
		{	
			node->type = LS;
			node->next->type = WRD_REDIR;
			free(node->next->value);
			node->next->value = ft_substr(name, 0, ft_strlen(name));
			break ;
		}
	}
}

int	heredoc(t_mylist *node, t_main *main, int *i)
{
	char	*error;
	int		fd;
	char	*name;

	name = here_file_name(*i);
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	*i += 1;
	if (fd < 0)
		return (error = ft_strjoin("minishell: ", name),
			perror(error), free(error), 0);
	read_heredoc_input(name, node, main, fd);
	close(fd);
	return (1);
}
