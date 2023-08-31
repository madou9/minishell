/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:11:06 by ihama             #+#    #+#             */
/*   Updated: 2023/08/14 20:39:00 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int			min_threshold;
	int			approximation;
	int			previous;

	min_threshold = 4;
	if (nb < 0)
		return (0);
	if (nb < min_threshold)
		return (1);
	approximation = nb / 2;
	previous = approximation + 1;
	while (previous - approximation > 1 || approximation * approximation > nb)
	{
		previous = approximation;
		approximation = (previous + nb / previous) / 2;
	}
	return (approximation);
}
