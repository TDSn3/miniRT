/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:09:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 02:36:18 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Parcours tous les objets de la liste stocké dans world.				  */
/*   Renvois les intersections entre le rayon et les objects				  */
/*   dans une liste triée t_to.												  */
/*   Si l'intersection vaut 0, ne copie pas dans la liste.    				  */
/*                                                                            */
/* ************************************************************************** */
/*t_to	*intersect_world(t_world *world, t_ray ray)
{
	t_to			*ret;
	t_object		*cpy;
	t_intersection	t;

	ret = NULL;
	cpy = world->lst_object;
	while (cpy)
	{
		t = intersect(ray.vector, ray.point, cpy);
		if (t.t[1])
			sto_add_back(&ret, sto_new(t.t[1], cpy));
		if (t.t[2])
			sto_add_back(&ret, sto_new(t.t[2], cpy));
		cpy = cpy->next;
	}
	sto_sort(&ret);
	return (ret);
}*/

t_object	intersect_world(t_object const *objects, t_ray const *ray)
{
	t_object		ret;
	t_object const	*obj;
	t_intersection	t;

	ret.t = FLT_MAX;

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
