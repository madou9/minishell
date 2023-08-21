/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/21 21:43:46 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
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

// char **dup_env(char **env);
void	print_args(char **args);
int		execute_echo(char **args);
int		execute_exit(char **args);
void	execute_pwd(char **argv);
int		execute_env(t_redr *tmp);
char	**dup_env(char **env);
//void	update_environment(t_redr *direction, char *new_var);
// bool	check_variable(char *var, t_redr *direc);
int		execute_export(char **args, t_redr *direction);
void	update_export(char **args, t_redr *envpp);
#endif