/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 04:48:12 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:13:54 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	while (i < len && s[start] != '\0')
	{
		buffer[i] = s[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}
