/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:08:30 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:24:58 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	len;

	len = ft_strlen((char *)s1) + 1;
	d = malloc(len);
	if (!d)
		return (0);
	ft_strlcpy(d, (char *)s1, len);
	return (d);
}
