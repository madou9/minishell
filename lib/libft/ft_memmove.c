/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:05:03 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:23:26 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*dest_cast;
	char	*src_cast;
	size_t	i;	

	src_cast = (char *)src;
	dest_cast = (char *)dest;
	i = -1;
	if (!dest && !src)
		return (0);
	if (dest_cast < src_cast)
	{
		while (++i < n)
			dest_cast[i] = src_cast[i];
	}
	else
	{
		while (n > 0)
		{
			dest_cast[n - 1] = src_cast[n - 1];
			n--;
		}
	}
	return (dest);
}
