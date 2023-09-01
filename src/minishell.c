/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/01 17:59:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	should_execute_command(char **args, t_redr *env)
{
	int		i;
	int		tmpfd;

	/*Duplicate STDOUT before the loop */
	i = -1;
	tmpfd = dup(STDOUT_FILENO);
	while (args[++i])
	{
		if (is_builtin(args[i]))
		{
			if (check_redirection(args))
			{
				//printf("redirection : %s\n", *args);
				execute_builtins(&args[i], env);
				break ;
			}
		}
		else
			//printf("redirection else : %s\n", *args);
			execute_external(&args[i], env);
	}
	// Restore the original STDOUT outside of the loop
	dup2(tmpfd, STDOUT_FILENO);
	close(tmpfd);
}

// void should_execute_command(char **args, t_redr *env)
// {
//     if (check_redirection(args))
// 	{
//         if (is_builtin(args[0]))
// 		{
//             execute_builtins(args, env);
//         }
// 		else
// 		{
//             execute_external(args, env);
//         }
//     }
// }


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
		message = readline("MinniShell$->: ");
		temp = history_tokenize(message);
		add_history(message);
		if (temp[0])
			should_execute_command(temp, glob);
		free(message);
		free(temp);
	}
	return (0);
}
