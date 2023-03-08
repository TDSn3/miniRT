/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_caps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:24:28 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:58:09 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	check_cap(t_ray ray, float t);

/* ************************************************************************** */
/*                                                                            */
/*   ATTENTION																  */
/*   ray.vector.y >= -0.1 && ray.vector.y <= 0.1                              */
/*                                                                            */
/* ************************************************************************** */
void	intersect_caps(t_ray ray, t_object *object, t_intersection *ret)
{
	float	t;

	if (!object->cyl_closed || (ray.vector.y >= -0.1 && ray.vector.y <= 0.1))
		return ;
	t = (object->cyl_min - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		if (ret->t[2] == 0)
			ret->t[2] = t;
		else if (ret->t[1] == 0)
			ret->t[1] = t;
	}
	t = (object->cyl_max - ray.point.y) / ray.vector.y;
	if (check_cap(ray, t))
	{
		if (ret->t[1] == 0)
			ret->t[1] = t;
		else if (ret->t[2] == 0)
			ret->t[2] = t;
	}
}

static int	check_cap(t_ray ray, float t)
{
	float	x;
	float	z;

	x = ray.point.x + t * ray.vector.x;
	z = ray.point.z + t * ray.vector.z;
	return (x * x + z * z <= 1);
}
