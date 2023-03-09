/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:09:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:38 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_object	intersect_world(t_object const *objects, t_ray const *ray)
{
	t_object		ret;
	t_object const	*obj;
	t_intersection	t;

	ret.t = INFINITY;
	obj = objects;
	while (obj)
	{
		t = intersect(ray->vector, ray->point, obj);
		if (t.t[1] && t.t[1] < ret.t)
		{
			ret = *obj;
			ret.t = t.t[1];
		}
		if (t.t[2] && t.t[2] < ret.t)
		{
			ret = *obj;
			ret.t = t.t[2];
		}
		obj = obj->next;
	}
	return (ret);
}
