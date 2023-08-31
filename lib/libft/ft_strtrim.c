/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:16:38 by ihama             #+#    #+#             */
/*   Updated: 2023/04/04 00:35:51 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*trim;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && ft_isset(*start, set))
		start++;
	end = s1 + ft_strlen(s1) -1;
	while (end > start && ft_isset(*end, set))
		end--;
	trim = ft_substr(start, 0, end - start + 1);
	return (trim);
}
