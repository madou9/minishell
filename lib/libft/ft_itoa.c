/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:35:22 by ihama             #+#    #+#             */
/*   Updated: 2023/04/01 11:35:02 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	digit_count(int n)
{
	int	digit;

	digit = !n;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	bool	sign;
	int		d_count;
	char	*result;

	sign = n < 0;
	d_count = digit_count(n) + sign;
	result = (char *)malloc(sizeof(char) * (d_count + 1));
	if (!result)
		return (NULL);
	result[d_count] = 0;
	if (sign)
	{
		*result = '-';
		result[--d_count] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (d_count-- - sign)
	{
		result[d_count] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
