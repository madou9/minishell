# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihama <ihama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 20:54:02 by voszadcs          #+#    #+#              #
#    Updated: 2023/08/24 20:31:24 by ihama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

VPATH 	= src/
SRCS	= minishell.c parser.c lexer.c builtins/exit_builtins.c builtins/echo_builtins.c builtins/pwd_builtins.c builtins/env_builtins.c  environnement/dup_env.c builtins/export_builtins.c \
		   builtins/unset_builtins.c builtins/cd_builtins.c builtins/builtins.c
OBJS	= $(SRCS:.c=.o)

CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

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
