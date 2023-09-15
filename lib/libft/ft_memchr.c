/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:42:16 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 04:32:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	b;

	b = (char)c;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	return (0);
}
