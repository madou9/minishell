/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:48 by ihama             #+#    #+#             */
/*   Updated: 2023/08/29 19:09:08 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_printchar(int c);
int		format_check(va_list args, const char format);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *str);
int		ft_hexa_forma(unsigned long long n);
int		ft_hexa_deci(int n);
int		ft_unsigned_deci(unsigned int c);
int		ft_hexa_low(unsigned int n);
int		ft_hexa_uper(unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_sqrt(int nb);
int		ft_isalpha_cha(char c);

/* Bonus functions */
typedef struct s_data
{
	void			*content;
	struct s_data	*next;
}				t_data;

t_data	*ft_lstnew(void *content);
void	ft_lstadd_front(t_data **lst, t_data *new);
int		ft_lstsize(t_data *lst);
t_data	*ft_lstlast(t_data *lst);
void	ft_lstadd_back(t_data **lst, t_data *new);
void	ft_lstdelone(t_data *lst, void (*del)(void *));
void	ft_lstclear(t_data **lst, void (*del)(void *));
void	ft_lstiter(t_data *lst, void (*f)(void *));
t_data	*ft_lstmap(t_data *lst, void *(*f)(void *), void (*del)(void *));

#endif 