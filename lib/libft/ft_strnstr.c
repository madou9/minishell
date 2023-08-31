/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:16:17 by ihama             #+#    #+#             */
/*   Updated: 2023/04/04 13:27:53 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	int					n;

	i = 0;
	while (haystack[i] != '\0')
	{	
		n = 0;
		while (i < len && haystack[i] != '\0' && haystack[i] == needle[n])
		{
			i++;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)&haystack[i - n]);
		i = (i - n) + 1;
	}
	if (needle == NULL || ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) > len)
		return (0);
	return (0);
}
