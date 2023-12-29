/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/20 02:20:26 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	g_error_code = 0;

int	is_not_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (add_history(str), 0);
	return (1);
}

void	main_list(char *message, t_main *main)
{
	add_history(message);
	main->list = NULL;
	lexer(message, main);
	expand_tokens(main);
	postsplit(main);
	if (parser(main) == 0)
	{
		execute(main);
		rm_tmp_files(main->heredocs, main);
	}
}

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_main		main;

	if (argc > 1)
		return (printf("%s: %s: no such file or directory\n",
				argv[0], argv[1]), 1);
	main.env = dup_env(env);
	while (1)
	{
		signal_handler(0);
		message = readline("minishell$: ");
		if (message == NULL)
			break ;
		if (message[0] != '\0' && is_not_spaces(message))
		{
			main_list(message, &main);
			free_main_process(&main);
		}
	}
	free(message);
	return (0);
}
