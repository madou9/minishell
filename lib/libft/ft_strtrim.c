/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:10:36 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/15 05:25:53 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_front(char *src, char *trim)
{	
	int	i;
	int	k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (src[i] != '\0')
	{
		if (trim[k] == src[i])
		{
			count++;
			i++;
			k = 0;
		}
		else if (trim[k] != src[i] && trim[k] != '\0')
			k++;
		else if (trim[k] == '\0')
			break ;
	}
	return (count);
}

static int	ft_back(char *src, char *trim)
{
	int	i;
	int	k;
	int	count;

	k = 0;
	count = 0;
	i = ft_strlen(src) - 1;
	while (i >= 0)
	{
		if (trim[k] == src[i])
		{
			count++;
			i--;
			k = 0;
		}
		else if (trim[k] != src[i] && trim[k] != '\0')
			k++;
		else if (trim[k] == '\0')
			break ;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	int		i;
	int		len;
	size_t	count1;
	size_t	count2;

	if (!s1)
		return (NULL);
	count1 = ft_front((char *)s1, (char *)set);
	count2 = ft_back((char *)s1, (char *)set);
	if (count1 == ft_strlen((char *)s1))
		count2 = 0;
	len = ft_strlen((char *)s1) - (count1 + count2);
	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, len + 1);
	i = 0;
	while (i < len)
	{
		buffer[i] = s1[count1];
		count1++;
		i++;
	}
	return (buffer);
}
