# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihama <ihama@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:58:01 by ihama             #+#    #+#              #
#    Updated: 2023/08/14 15:55:03 by ihama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   libft.a
CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror
SRCS        =   ft_isalpha.c ft_putstr.c \
				ft_isdigit.c ft_hexa_forma.c \
				ft_memchr.c ft_hexa_deci.c  \
				ft_memcpy.c ft_printchar.c \
				ft_memset.c ft_unsigned_deci.c \
				ft_strlen.c  ft_hexa_low.c \
				ft_tolower.c  ft_hexa_uper.c \
				ft_bzero.c   ft_strcmp.c \
				ft_isalnum.c ft_sqrt.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_memmove.c \
				ft_toupper.c \
				ft_strchr.c  \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_memcmp.c	 \
				ft_strnstr.c \
				ft_atoi.c	 \
				ft_calloc.c  \
				ft_strdup.c  \
				ft_substr.c  \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c  \
				ft_itoa.c    \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_printf.c \
				
SRCS_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)					
				   
OBJS            = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
bonus: $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
fclean: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
re: fclean all bonus
$(OBJS): %.o:%.c ft_*.c
	@$(CC) $(CFLAGS) -c $< -o $@
.PHONY: all fclean clean bonus re