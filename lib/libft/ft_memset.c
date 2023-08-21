/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:04:40 by voszadcs          #+#    #+#             */
/*   Updated: 2022/10/20 01:10:48 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int a, size_t len)
{
	unsigned long	i;
	char			*c;

	c = (char *)s;
	i = 0;
	while (i < len)
	{
		c[i] = a;
		i++;
	}
	return (s);
}
