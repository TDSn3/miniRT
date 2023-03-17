/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:09:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/17 18:56:03 by tda-silv         ###   ########.fr       */
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
t_to	intersect_world(t_world *world, t_ray ray)
{
	t_to			ret;
	t_object		*cpy;
	t_intersection	t;

	ret.t = DBL_MAX;
	ret.object = NULL;
	cpy = world->lst_object;
	while (cpy)
	{
		t = intersect(ray.vector, ray.point, cpy);
		if (t.t.b && t.t.b < ret.t)
		{
			ret.t = t.t.b;
			ret.object = cpy;
		}
		if (t.t.c && t.t.c < ret.t)
		{
			ret.t = t.t.c;
			ret.object = cpy;
		}
		cpy = cpy->next;
	}
	return (ret);
}
