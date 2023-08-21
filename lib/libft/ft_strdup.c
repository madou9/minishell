/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:08:30 by voszadcs          #+#    #+#             */
/*   Updated: 2023/08/20 16:57:17 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*d;
	uint32_t	len;

	len = ft_strlen((char *)s1) + 1;
	d = malloc(len);
	if (!d)
		return (0);
	ft_strlcpy(d, (char *)s1, len);
	return (d);
}
