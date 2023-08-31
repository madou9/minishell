/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:54:12 by ihama             #+#    #+#             */
/*   Updated: 2023/03/31 02:41:40 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*result;

	i = ft_strlen(s1) + 1;
	result = (char *)malloc(sizeof(char) * i);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, i);
	return (result);
}
