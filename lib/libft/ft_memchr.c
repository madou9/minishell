/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 03:12:27 by ihama             #+#    #+#             */
/*   Updated: 2023/03/27 04:39:06 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*x;

	i = 0;
	x = (const char *) s;
	while (i < n)
	{
		if (*(x + i) == (char)c)
			return ((void *)(x + i));
		i++;
	}
	return (NULL);
}
