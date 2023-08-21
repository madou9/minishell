/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:08:26 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/02 16:36:48 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{	
	int		i;
	char	*buffer;

	i = 0;
	if (!s)
		return (NULL);
	buffer = malloc(ft_strlen((char *) s) + 1);
	if (!buffer)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = (*f)(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
