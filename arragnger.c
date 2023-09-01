// void export_variable(char **args, t_redr *envpp) {
//     int i = 0;

//     while (args[i] != NULL) {
//         char *var_name = args[i];
//         char *equal_sign = ft_strchr(var_name, '=');
//         // Check if equal_sign is the first character (e.g., "=value")
//         if (equal_sign == var_name) {
//             printf("export: %s: not a valid identifier\n", var_name);
//             i++;
//             continue;
//         }
//         // Check if var_name is a valid identifier
//         if (!is_valid_identifier(var_name)) {
//             printf("export: %s: not a valid identifier\n", var_name);
//             i++;
//             continue;
//         }

//         // Now, check if the variable should be exported
//         if (equal_sign != NULL) {
//             update_or_add_variable(envpp, var_name);
//         } else {
//             // If var_name does not contain '=', it should be added to the environment
//             update_environment(envpp, var_name);
//         }

//         i++;
//     }
// }

// void	export_variable(char **args, t_redr *envpp)
// {
// 	char	*equal_sign;
// 	bool	valid_identifier;
// 	char	*var_name;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (args[i] != NULL)
// 	{
// 		var_name = args[i];
// 		valid_identifier = true;
// 		var_name = args[i];
// 		j = 0;
// 		while (var_name[j] != '=' && var_name[j] != '\0')
// 		{
// 			if (!ft_isalpha_cha(var_name[j]) && var_name[j] != '_')
// 			{
// 				valid_identifier = false;
// 				break ;
// 			}
// 			j++;
// 			if (!valid_identifier)
// 				printf("export: %s: not a valid identifier\n", var_name);
// 			i++;
// 			equal_sign = ft_strchr(var_name, '=');
// 			if (equal_sign != NULL)
// 				update_or_add_variable(envpp, var_name);
// 			else
// 			{
// 				if (ft_strcmp(var_name, "=") > 0)
// 					update_environment(envpp, var_name);
// 			}
// 			i++;
// 		}
// 	}
// }