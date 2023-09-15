/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:47:57 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/15 11:39:08 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execute(t_main *main)
{
	int		i;

	i = 0;
	while (i < main->procs)
	{
		if (is_builtin(main->data[i].cmd[0]))
			execute_builtins(&main->data[i], main);
		else
			if (execute_external(&main->data[i], main) == -1)
				return ;
		i++;
	}
}

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
// Need to fix env duplication in case of no original env

int	main(int argc, char **argv, char **env)
{
	char		*message;
	t_main		main;
	// t_mylist	*head;

	if (argc > 1)
		return (printf("%s: %s: no such file or directory\n", argv[0], argv[1]), 1);
	main.env = dup_env(env);
	main.error_code = 0;
	while (1)
	{
		message = readline("minishell$->: ");
		if (message[0] != '\0' && is_not_spaces(message))
		{
			add_history(message);
			main.list = NULL;
			lexer(message, &main);
			expand_tokens(&main);
			postsplit(&main);
			if (parser(&main) == 0)
			{
				execute(&main);
			}
		}
	}
	return (0);
}
			// 
			// {
			// 	while (i < main.procs)
			// 	{
			// 		printf("Command %d: ", i);
			// 		while (main.data[i].cmd[j] != NULL)
			// 		{
			// 			printf("%s ", main.data[i].cmd[j]);
			// 			free(main.data[i].cmd[j]);
			// 			j++;
			// 		}
			// 		printf("\ninput fd = %d\n", main.data[i].fd[0]);
			// 		printf("output fd = %d\n", main.data[i].fd[1]);
			// 		free(main.data[i].cmd);
			// 		i++;
			// 		j = 0;
			// 	}
			// // 	i = 0;
			// // 	while (i < main.procs)
			// // 	{
			// // 		if (close(main.data[i].fd[0]) < 0)
			// // 			printf("GALACTIC LOOP\n");
			// // 		if (close(main.data[i].fd[1]) < 0)
			// // 			printf("GALACTIC LOOP\n");
			// // 		i++;
			// // 	}
			// // 	free(main.data);
			// // }