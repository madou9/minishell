/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:04:16 by ihama             #+#    #+#             */
/*   Updated: 2023/08/02 19:38:00 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_check(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_hexa_forma(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_hexa_deci(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsigned_deci(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_hexa_low(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_hexa_uper(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_printchar(format);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	elem;
	int		i;
	int		l;

	i = 0;
	l = 0;
	va_start(elem, s);
	while (s[i])
	{
		if (s[i] == '%')
			l += format_check(elem, s[++i]);
		else
			l += ft_printchar(s[i]);
		i++;
	}
	va_end(elem);
	return (l);
}
