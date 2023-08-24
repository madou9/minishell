/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:26 by ihama             #+#    #+#             */
/*   Updated: 2023/08/24 22:00:12 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execute_builtins(char **args, t_redr *envpp)
{
	if (!strcmp(args[0], "echo"))
		execute_echo(args);
	else if (!strcmp(args[0], "exit"))
		execute_exit(args);
	else if (!strcmp(args[0], "pwd"))
		execute_pwd(args);
	else if (!strcmp(args[0], "env"))
		execute_env(envpp);
	else if (!strcmp(args[0], "export"))
		execute_export(args, envpp);
	else if (!strcmp(args[0], "unset"))
		execute_unset(args, envpp);
	else if (!strcmp(args[0], "cd"))
		execute_cd(args, envpp);
}

int	is_builtin(const char *command)
{
	return (!strncmp(command, "echo", 4)
		|| (!strncmp(command, "exit", 4))
		|| (!strncmp(command, "pwd", 3))
		|| (!strncmp(command, "env", 3))
		|| (!strncmp(command, "export", 6))
		|| (!strncmp(command, "unset", 5))
		|| !strncmp(command, "cd", 2));
}

char	*get_path_cmd(char *cmd, char **env)
{
	char	**all_path;
	char	*cmd_path;
	char	*new_sub;

	while (*env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	new_sub = ft_substr(*env, 5, ft_strlen(*env) - 5);
	all_path = ft_split(new_sub, ':');
	free(new_sub);
	cmd = *ft_split(cmd, ' ');
	new_sub = ft_strjoin("/", cmd);
	while (*all_path)
	{
		cmd_path = ft_strjoin(*all_path, new_sub);
		if (cmd_path == 0)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			break ;
		free(cmd_path);
		all_path++;
	}
	free(new_sub);
	free(cmd);
	return (cmd_path);
}

void	execute_external(char **args, t_redr *envpp)
{
	char	*cmd_path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		printf("fork error");
	else if (pid == 0)
	{
		cmd_path = get_path_cmd(args[0], envpp->env);
		if (!cmd_path)
		{
			printf("fork error");
			exit(EXIT_FAILURE);
		}
		execve(cmd_path, args, envpp->env);
	}	
	waitpid(pid, &status, 0);
}
