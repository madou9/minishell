/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:36:52 by ihama             #+#    #+#             */
/*   Updated: 2023/04/04 00:36:21 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*x;

	i = 0;
	n = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start > n)
		start = n;
	if (len > n - start)
		len = n - start;
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
