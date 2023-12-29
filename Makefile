# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 20:54:02 by voszadcs          #+#    #+#              #
#    Updated: 2023/09/20 01:01:51 by voszadcs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

VPATH 	= src/
SRCS	= minishell.c parser.c lexer.c lexer_utils.c expansion.c\
		expansion_utils.c dup_env.c postsplit.c split_utils.c remove_quotes.c signal.c\
		parser_utils.c parse_redir.c do_redir.c parse_command.c heredoc.c execute.c pipe_utils.c errors.c liberator.c\
		builtins/echo_builtins.c builtins/builtins.c builtins/env_builtins.c builtins/export_builtins.c builtins/utils_builtins.c\
		builtins/pwd_builtins.c builtins/exit_builtins.c builtins/unset_builtins.c builtins/cd_builtins.c\

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT	= lib/libft/libft.a

all: $(NAME)

$(LIBFT):
	make re -C lib/libft && make clean -C lib/libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) -lreadline
	make clean

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all