/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:45:25 by voszadcs          #+#    #+#             */
/*   Updated: 2022/11/13 19:36:07 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{	
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			ft_putnbr_fd(214748364, fd);
			write(fd, "8", 1);
			return ;
		}
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		if (n >= 0)
			ft_putchar_fd(n + 48, fd);
}
