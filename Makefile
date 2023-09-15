# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihama <ihama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 20:54:02 by voszadcs          #+#    #+#              #
#    Updated: 2023/09/15 00:15:05 by ihama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

VPATH 	= src/
SRCS	= minishell.c parser.c lexer.c errors.c lexer_utils.c expansion.c\
		expansion_utils.c dup_env.c postsplit.c split_utils.c remove_quotes.c\
		parser_utils.c parse_redir.c do_redir.c parse_command.c \
		builtins/echo_builtins.c builtins/builtins.c builtins/env_builtins.c builtins/export_builtins.c builtins/utils_builtins.c\
		builtins/pwd_builtins.c builtins/exit_builtins.c builtins/unset_builtins.c builtins/cd_builtins.c\
		
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

LIBFT	= lib/libft/libft.a

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./lib/libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME) -lreadline

clean:
	@$(MAKE) clean -C ./lib/libft
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
