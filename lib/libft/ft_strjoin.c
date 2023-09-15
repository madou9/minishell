/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:27:33 by voszadcs          #+#    #+#             */
/*   Updated: 2023/09/06 16:35:23 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//Changed from original Libft ft_strjoin. Now if any string as parameter is NULL
//function takes it as 0 length;
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		size1;
	int		size2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		size1 = 0;
	else
		size1 = ft_strlen((char *)s1);
	if (s2 == NULL)
		size2 = 0;
	else
		size2 = ft_strlen((char *)s2);
	i = 0;
	str = malloc(size1 + size2 + 1);
	if (!str)
		return (NULL);
	while (s1 != NULL && *s1 != 0)
		str[i++] = *(char *)s1++;
	while (s2 != NULL && *s2 != 0)
		str[i++] = *(char *)s2++;
	str[i] = '\0';
	return (str);
}
