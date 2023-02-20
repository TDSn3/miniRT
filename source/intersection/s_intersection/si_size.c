/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 21:20:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	si_size(t_intersection *lst)
{
	t_intersection	*nextl;
	size_t			i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		nextl = nextl->next;
		i++;
	}
	return (i);
}
