bool	is_export_valid(char *valu)
{
	int	i;

	i = 0;
	if (!ft_isalpha_cha(*valu))
		return (false);
	while (valu[i])
	{
		if (valu[i] == '=' || (valu[i] == '+' && valu[i + 1] == '='))
			return (true);
		i++;
	}
	return (false);
}

bool	is_token_valid_export(char *args)
{
	if (is_export_valid(args))
	{
		ft_putstr_fd("export not a valid identifier ", STDERR_FILENO);
		ft_putstr_fd(args, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

int execute_export(char **args, t_redr *direction)
{
    int i;
    char **env;

    i = 0;
	env = direction->env;
	if (args[1] != NULL)
		update_export(args, direction);
    while (env[i] != NULL)
    {
        if (ft_strchr(env[i], '='))
        {
            ft_putstr_fd("declare -x ", STDOUT_FILENO);
            // Print variable name until '='
            int j = 0;
            while (env[i][j] != '=')
            {
                ft_putchar_fd(env[i][j], STDOUT_FILENO);
                j++;
            }
            // Print variable value enclosed in double quotes
            printf("=\"%s\"\n", &env[i][j + 1]);
        }
        i++;
		update_export(args, direction);
    }
    return (EXIT_SUCCESS);
}