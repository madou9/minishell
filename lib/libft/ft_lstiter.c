/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 06:08:14 by ihama             #+#    #+#             */
/*   Updated: 2023/08/14 16:33:54 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_data *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}
