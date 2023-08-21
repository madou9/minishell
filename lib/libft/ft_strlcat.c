/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:08:22 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:26:31 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (dst)
		i = ft_strlen(dst);
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[k] && k < dstsize - i - 1)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
