/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/31 14:48:29 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_redr		*glob;	
	char		**temp;
	char		check;
	int tmpfd = dup(STDOUT_FILENO);
	(void) argc;
	(void) argv;

	glob = malloc(sizeof(t_redr));
	glob->env = dup_env(env);
	while (1)
	{
		message = readline("MinniShell$->: ");
		temp = history_tokenize(message);
		add_history(message);
		if (temp[0])
		{
			check = check_redirection(temp);
			if (check)
				execute_external(temp, glob);
			else if (is_builtin(temp[0]))
				execute_builtins(temp, glob);
		}
		free(message);
		free(temp);
		dup2(tmpfd, STDOUT_FILENO);

	}
	return (0);
}
