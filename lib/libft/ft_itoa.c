/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:31:10 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/13 23:13:34 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_len(long int n, int i)
{
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*fill(long int num, int i, char *buff, int len)
{
	if (num < 0)
	{
		num = num * -1;
		buff[0] = '-';
		while (i > 0)
		{
			buff[i] = num % 10 + '0';
			num = num / 10;
			i--;
		}
		buff[len] = '\0';
		return (buff);
	}
	while (i >= 0)
	{
		buff[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	buff[len] = '\0';
	return (buff);
}

char	*ft_itoa(int n)
{
	char		*buff;
	long int	num;
	int			len;
	int			i;

	num = (long int)n;
	len = itoa_len(num, 1);
	i = len -1;
	buff = malloc(len + 1);
	if (!buff)
		return (NULL);
	return (fill(num, i, buff, len));
}
