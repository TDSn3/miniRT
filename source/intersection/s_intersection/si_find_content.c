/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_find_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:06:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 21:29:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_intersection	*si_find_content(t_intersection *lst, unsigned int object_id)
{
	t_intersection	*nextl;
	size_t			i;

	i = 0;
	nextl = lst;
	if (!lst)
		return (0);
	while (nextl)
	{
		if (nextl->object.id == object_id)
			return (nextl);
		nextl = nextl->next;
		i++;
	}
	return (NULL);
}
