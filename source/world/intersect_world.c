/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:09:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 14:36:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	*intersect_world(t_world *world, t_ray ray)
{
	t_to			*ret;
	t_object		*cpy;
	t_intersection	t;

	ret = NULL;
	cpy = world->lst_object;
	while (cpy)
	{
		t = intersect(ray.vector, ray.point, cpy);
		sto_add_back(&ret, sto_new(t.t.b, cpy));
		sto_add_back(&ret, sto_new(t.t.c, cpy));
		cpy = cpy->next;
	}
	sto_sort(&ret);
	return (ret);
}
