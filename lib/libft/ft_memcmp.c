/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:20:48 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:23:07 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*first;
	char	*second;
	size_t	i;

	first = (char *)s1;
	second = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] == second[i])
		{
			i++;
		}
		else
			return ((unsigned char)first[i] - (unsigned char)second[i]);
	}
	return (0);
}
