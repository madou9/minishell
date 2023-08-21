/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:26 by ihama             #+#    #+#             */
/*   Updated: 2023/08/19 18:06:38 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	**dup_env(char **env)
{
	char	**new_env;
	int		i;

	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	char	*message;

	g_env = dup_env(env);

	while (1)
	{
		message = readline("MinniShell$: ");
		add_history(message);
		if (strcmp(argv[0], "echo") == 0)
			execute_echo(argv);
		else if (strcmp(argv[0], "cd") == 0)
			execute_cd(argv);
		else if (strcmp(argv[0], "pwd") == 0)
			execute_pwd();
		else if (strcmp(argv[0], "export") == 0)
			execute_export(argv);
		else if (strcmp(argv[0], "unset") == 0)
			execute_unset(argv);
		else if (strcmp(argv[0], "env") == 0)
			execute_env();
		else if (strcmp(argv[0], "exit") == 0)
			execute_exit();
		else
		{
			// Handle external commands using fork and exec
			// ...
		}

	}
	return 0;
}