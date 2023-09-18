/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:51:26 by ihama             #+#    #+#             */
/*   Updated: 2023/09/16 00:44:52 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execute_builtins(t_data *data, t_main *main)
{
	if (!ft_strcmp(data->cmd[0], "echo"))
		execute_echo(data);
	else if (!ft_strcmp(data->cmd[0], "exit"))
		execute_exit(data);
	else if (!ft_strcmp(data->cmd[0], "pwd"))
		execute_pwd(data->cmd);
	else if (!ft_strcmp(data->cmd[0], "env"))
		execute_env(main);
	else if (!ft_strcmp(data->cmd[0], "export"))
		execute_export(data, main);
	else if (!ft_strcmp(data->cmd[0], "unset"))
		execute_unset(data, main);
	else if (!ft_strcmp(data->cmd[0], "cd"))
		execute_cd(data, main);
}

int	is_builtin(const char *command)
{
	return (!ft_strncmp(command, "echo", 4)
		|| (!ft_strncmp(command, "exit", 4))
		|| (!ft_strncmp(command, "pwd", 3))
		|| (!ft_strncmp(command, "env", 3))
		|| (!ft_strncmp(command, "export", 6))
		|| (!ft_strncmp(command, "unset", 5))
		|| !ft_strncmp(command, "cd", 2));
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

int	execute_external(t_data *data, t_main *main)
{
	char	*cmd_path;
	pid_t	pid;
	int		status;
	char	*error;

	pid = fork();
	if (pid == -1)
		printf("fork error");
	else if (pid == 0)
	{
		if (data->fd[0] != 0)
		{
			if (dup2(data->fd[0], STDIN_FILENO) == -1)
				return (perror("DUP2"), -1);
			close(data->fd[0]);
		}
		if (data->fd[1] != 1)
		{
			dup2(data->fd[1], STDOUT_FILENO);
			close(data->fd[1]);
		}
		cmd_path = get_path_cmd(data->cmd[0], main->env);
		if (execve(cmd_path, data->cmd, main->env) == - 1)
		{
			error = ft_strjoin("minishell: ", cmd_path);
			return (perror(error), free(error), -1);
		}
	}
	waitpid(pid, &status, 0);
	return (0);
}

