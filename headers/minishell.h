/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/27 20:59:03 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"

//Lexer types

# define PIPE 0
# define LSLS 1
# define GRTGRT 2
# define LS 3
# define GRT 4
# define WRD 5

//Errors
#define ERR_MALLOC 10

typedef struct s_redr
{
	char	**env;
	char	*input_file;
	char	*output_file;
	char	*value;
}	t_redr;

typedef struct s_mylist
{
	int				type;
	char			*value;
	struct s_mylist	*next;
}	t_mylist;

typedef struct s_input
{
	char	**cmd;
}	t_input;

//Functions

t_mylist	*lexer(char *str);

//Builtins function 

void	print_args(char **args);
int		execute_echo(char **args);
int		execute_exit(char **args);
void	execute_pwd(char **argv);
int		execute_env(t_redr *tmp);
char	**dup_env(char **env);
void	update_environment(t_redr *direction, char *new_var);
bool	update_or_add_variable(t_redr *envpp, char *new_var);
bool	is_token_valid_export(char *args);
int		execute_export(char **args, t_redr *direction);
void	print_export(t_redr *direction);
//void	update_export(char **args, t_redr *envpp);
int		execute_unset(char **args, t_redr *envpp);
bool	remove_variable(char **envpp, const char *var);
void	free_environment(char **envpp);
int		execute_cd(char **args, t_redr *direction);
char	*ft_getenv(char **env, const char *name);

int		home_case(char **args, t_redr *env);
int		old_pwd(char **args, t_redr *direction);

// builtins
void	execute_builtins(char **args, t_redr *envpp);
int		is_builtin(const char *command);
void	execute_external(char **args, t_redr *envpp);
// redirection 
int	input_redirection(char *infile);
int	output_redirection_append(char **args);
int	output_redirection(char **outfile);
int	check_redirection(char **args);
#endif