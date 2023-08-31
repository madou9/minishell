/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:29:11 by ihama             #+#    #+#             */
/*   Updated: 2023/03/27 04:42:57 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	x;

	x = (char) c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == x)
			last = (char *)s;
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (last);
}
