/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihama <ihama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:28:11 by ihama             #+#    #+#             */
/*   Updated: 2023/08/14 16:31:42 by ihama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	*ft_lstnew(void *content)
{
	t_data	*maillon;

	maillon = malloc(sizeof(t_data));
	if (!(maillon))
		return (NULL);
	maillon->content = content;
	maillon->next = NULL;
	return (maillon);
}
