void	handle_cmd(char **args, t_redr *envpp)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (check_redirection(&args[i + 2]))
			return ;
		else if (is_builtin(args[0]))
			execute_builtins(&args[0], envpp);
		else if (args[i][0])
			execute_external(*args, envpp->env);
		i++;
	}
}

void	execute_external(char *args, char **envpp)
{
	char	*cmd_path;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		printf("fork error");
	else if (pid == 0)
	{
		cmd_path = get_path_cmd(args, envpp);
		if (!cmd_path)
		{
			perror("Error: path not found\n");
			exit(EXIT_FAILURE);
		}
		execve(cmd_path, &args, envpp);
	}	
	waitpid(pid, &status, 0);
}


// execve("fullpath", ["echo", ">", "file", NULL], env);

// execve("/bin/cat", ["cat", NULL, "file", NULL], env);

