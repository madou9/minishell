/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:58:45 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/20 01:35:17 by voszadcs         ###   ########.fr       */
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
# include <sys/errno.h>
# include <signal.h>
# include <termios.h>
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
# define WRD_QUOTED 6
# define WRD_SINGLE_Q 7
# define WRD_REDIR 8
# define WRD_CMD 9
# define WRD_ARG 10
# define HEREDOC_QUOT 11

//Errors
# define ERR_MALLOC 10

extern int	g_error_code;

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
	int		index;
	int		fd[2];
}	t_data;

typedef struct s_pipes
{
	int	pipe[2];
}	t_pipes;

typedef struct s_main
{
	t_mylist	*list;
	char		**env;
	t_data		*data;
	int			procs;
	t_pipes		*pipes;
	pid_t		*pid;
	int			heredocs;
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
int			do_redir(t_main *main, int ind);
int			heredoc(t_mylist *node, t_main *main, int *i);
char		*get_var(char *str, int i, char **env);
int			check_pipe(t_mylist *head, t_main *main, int *i);
char		*here_file_name(int num);
void		parse_command(t_main *main);
void		execute(t_main *main);
void		is_not_found(t_main *main, char *cmd_path, char *cmd);
void		exec_fail(t_main *main);
void		free_child_process(t_main *main);
char		*get_path(t_main *main, int ind);
void		signal_handler(int main);
void		rm_tmp_files(int num, t_main *main);
void		expand_err(t_explst *node, int *i);
void		free_main_process(t_main *main);
void		c1(t_mylist **temp_list, t_mylist **temp, t_mylist **head);
void		c2(t_mylist **temp_list, t_mylist **temp, t_mylist **head);
t_mylist	*split_str(char *str);
t_mylist	*create_redir_node(int type, char *str);
/* unset */
int			execute_unset(t_data *data, t_main *main);
bool		remove_variable(char **envpp, const char *var);
int			is_token_valid_unset(char *token);
void		free_environment(char **envpp);

/* export  */

void		execute_export(t_data *data, t_main *main);
void		print_export(t_main *main);
void		export_variable(char **args, t_main *main);
bool		is_valid_identifier(const char *name);
bool		update_or_add_variable(t_main *main, char *new_var);

/* pwd */
void		execute_pwd(char **argv);

/* env */
int			execute_env(t_main *main);

/* exit */

int			execute_exit(t_data *data);
int			ft_exit_number(char *str);

/* echo */

int			execute_echo(t_data *data);
int			ft_repeat_str(char repeat, char *str, int start);

/* cd */
int			home_case(t_data *data, t_main *main);
int			execute_cd(t_data *data, t_main *main);
int			old_pwd(t_data *data, t_main *main);

/* builtins */
void		execute_builtins(t_data *data, t_main *main);
int			is_builtin(const char *command);
char		*get_path_cmd(char *cmd, char **env);
/* execution */

void		init_pipes(t_main *main);
void		do_pipes(t_pipes *pipes, int ind, int procs);
void		close_all_pipes(t_main *main);
char		**dup_env(char **env);
void		update_environment( t_main *main, char *new_var);
char		*ft_getenv(char **env, const char *name);
#endif
