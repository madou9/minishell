/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_forma.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:51:40 by ihama             #+#    #+#             */
/*   Updated: 2023/08/02 19:37:45 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned long long n)
{
	int		l;
	char	*s;

	s = "0123456789abcdef";
	l = 0;
	if (n > 15)
		l += ft_print_hex(n / 16);
	l += ft_printchar(s[n % 16]);
	return (l);
}

int	ft_hexa_forma(unsigned long long n)
{
	int	l;

	l = ft_putstr("0x");
	if (n == 0)
		l += ft_printchar('0');
	else
		l += ft_print_hex(n);
	return (l);
}
