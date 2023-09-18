/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/18 17:43:12 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
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
# define WRD_QUOTED 6
# define WRD_SINGLE_Q 7
# define WRD_REDIR 8
# define WRD_CMD 9
# define WRD_ARG 10
# define HEREDOC_QUOT 11

//Errors
# define ERR_MALLOC 10

typedef struct s_explst
{
	char			*str;
	struct s_explst	*next;
}	t_explst;
typedef struct s_mylist
{
	int				type;
	char			*value;
	struct s_mylist	*next;
}	t_mylist;

typedef struct s_data
{
	char	**cmd;
	int		fd[2];
	int		index;
}	t_data;

typedef struct s_main
{
	t_mylist	*list;
	char		**env;
	t_data		*data;
	int			procs;
	int			error_code;
}	t_main;

//Functions

void		lexer(char *str, t_main *main);
void		check_double_quotes(char *str, int *i, t_mylist *list);
void		check_single_quotes(char *str, int *i, t_mylist *list);
void		expand_tokens(t_main *main);
void		skip_char(char *str, int *j, int *i);
void		is_heredoc(t_mylist *node);
t_explst	*new_node(t_explst **list);
char		**dup_env(char **env);
void		postsplit(t_main *main);
void		skip_chars(char *str, int *i, int *j);
void		free_old_list(t_mylist *list);
void		list_iter(t_mylist **list, t_mylist *node);
void		remove_quotes(t_mylist *list);
int			parser(t_main *main);
void		parser_free(t_main *main);
int			count_procs(t_mylist *main);
int			parse_redir(t_main *main);
int			do_redir(t_data *data, t_mylist *node);
int			heredoc(t_data *data, t_mylist *node);
int			check_pipe(t_mylist *head, t_main *main, int *i);
void		parse_command(t_main *main);
//exec part

/* unset */
int		execute_unset(t_data *data, t_main *main);
bool	remove_variable(char **envpp, const char *var);
int		is_token_valid_unset(char *token);
void	free_environment(char **envpp);

/* export  */

void	execute_export(t_data *data, t_main *main);
void	print_export(t_main *main);
void	export_variable(char **args, t_main *main);
bool	is_valid_identifier(const char *name);
bool 	update_or_add_variable(t_main *main, char *new_var);

/* pwd */
void	execute_pwd(char **argv);

/* env */
int		execute_env(t_main *main);

/* exit */

int		execute_exit(t_data *data);
int		ft_exit_number(char *str);

/* echo */

int		execute_echo(t_data *data);
int		ft_repeat_str(char repeat, char *str, int start);

/* cd */
int		home_case(t_data *data, t_main *main);
int		execute_cd(t_data *data, t_main *main);
int		old_pwd(t_data *data,  t_main *main);

/* builtins */
void	execute_builtins(t_data *data, t_main *main);
int		is_builtin(const char *command);
char	*get_path_cmd(char *cmd, char **env);
int		execute_external(t_data *data, t_main *main);

/* execution */

char	**dup_env(char **env);
void	update_environment( t_main *main, char *new_var);
void 	execute(t_main *main);
char	*ft_getenv(char **env, const char *name);
void	signal_handler(void);
void	handle_global_signals(void);
#endif
