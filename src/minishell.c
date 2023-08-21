/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/20 19:48:23 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_redr		*glob;	
	char		**temp;
	(void) argc;
	(void) argv;

	glob = malloc(sizeof(t_redr));
	glob->env = dup_env(env);
	while (1)
	{
		message = readline("MinniShell$: ");
		temp = history_tokenize(message);
		add_history(message);
		if (temp[0])
		{
			if (!strcmp(temp[0], "echo"))
				execute_echo(temp);
			else if (!strcmp(temp[0], "exit"))
				execute_exit(temp);
			else if (!strcmp(temp[0], "pwd"))
				execute_pwd(temp);
			else if (!strcmp(temp[0], "env"))
				execute_env(glob);
			else if (!strcmp(temp[0], "export"))
				execute_export(temp, glob);
		}
	    free(message);
        free(temp);  
	}
	return (0);
}
