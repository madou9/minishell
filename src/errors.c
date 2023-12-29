/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:49:02 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/19 22:29:30 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	is_not_found(t_main *main, char *cmd_path, char *cmd)
{
	if (cmd_path == NULL)
	{
		printf("minishell: %s: command not found\n", cmd);
		g_error_code = 127;
		free_child_process(main);
		exit(g_error_code);
	}
	else if (access(cmd_path, X_OK) != 0)
	{	
		printf("minishell: %s: Permission denied\n", cmd);
		g_error_code = 126;
		free_child_process(main);
		exit(g_error_code);
	}
}

void	exec_fail(t_main *main)
{
	perror("minishell: ");
	g_error_code = errno;
	free_child_process(main);
}
