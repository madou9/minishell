/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:45:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/30 15:03:58 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	export_variable(char *var, t_redr *envpp)
// {
// 	char	*equal_sign;
// 	char	*var_name;

// 	var_name = ft_strchr(var, '=');
// 	if (var_name != NULL) {
// 		// Handle export KEY=value case
// 		update_or_add_variable(envpp, var);
// 	} else {
// 		// Handle export KEY case
// 		// Print the environment variable if it exists
// 		char *value = ft_getenv(envpp->env, var);
// 		if (value != NULL) {
// 			printf("declare -x %s=\"%s\"\n", var, value);
// 		}
// 	}
// }

// int	execute_export(char **args, t_redr *direction)
// {
// 	if (args[1] == NULL) {
// 		// Print all exported variables
// 		print_export(direction);
// 	} else {
// 		// Export variables as per arguments
// 		for (int i = 1; args[i] != NULL; i++) {
// 			export_variable(args[i], direction);
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }


bool is_valid_variable_name(const char *token) {
    if (!token || !*token || !isalpha((unsigned char)token[0]) && token[0] != '_') {
        return false; // Token doesn't start with a letter or underscore
    }
    
    for (const char *c = token + 1; *c; c++) {
        if (!isalnum((unsigned char)*c) && *c != '_') {
            return false; // Token contains characters other than letters, digits, and underscores
        }
    }
    
    return true;
}

int execute_unset(char **args, t_redr *envpp) {
    for (int i = 1; args[i] != NULL; i++) {
        if (!is_valid_variable_name(args[i])) {
            fprintf(stderr, "unset: %s: invalid variable name\n", args[i]);
        } else if (!remove_variable(envpp->env, args[i])) {
            fprintf(stderr, "unset: %s: variable not found\n", args[i]);
        }
    }
    return EXIT_SUCCESS;
}

int	is_token_valid_unset(char *token_str, char *err_message)
{
	int		check;

	if (token_str == 0)
		return (1);
	if (ft_strchr(token_str, '=')
		|| ft_strchr(token_str, '\'')
		|| ft_strchr(token_str, '"')
		|| ft_strchr(token_str, '$')
		|| *token_str == '/'
		|| ft_isdigit(*token_str))
	{
		check = 0;
		ft_strcpy(err_message, "unset: `");
		ft_strcat(err_message, token_str);
		ft_strcat(err_message, "': not a valid identifier");
	}
	else
		check = 1;
	return (check);
