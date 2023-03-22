/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:11:27 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 11:24:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	abc_discri_calculating(t_3f *abc, double *discriminant, t_ray ray);
static void	swap(double *a, double *b);

/* ************************************************************************** */
/*                                                                            */
/*   ty.a   t0																  */
/*   ty.b   t1																  */
/*   ty.c   y0																  */
/*   ty.d   y1																  */
/*                                                                            */
/* ************************************************************************** */
t_intersection	intersect_cylinder(t_ray ray, t_object *cylinder)
{
	t_intersection	ret;
	t_3f			abc;
	double			discriminant;
	t_6f			ty;

	ret = (t_intersection){0};
	ret.object = cylinder;
	if (abc_discri_calculating(&abc, &discriminant, ray))
		return (ret);
	ret.t.a = 2;
	ty.a = (-abc.b - sqrtf(discriminant)) / (2 * abc.a);
	ty.b = (-abc.b + sqrtf(discriminant)) / (2 * abc.a);
	if (ty.a > ty.b)
		swap(&ty.a, &ty.b);
	ty.c = ray.point.y + ty.a * ray.vector.y;
	if (cylinder->cyl_min < ty.c && ty.c < cylinder->cyl_max)
		ret.t.b = ty.a;
	ty.d = ray.point.y + ty.b * ray.vector.y;
	if (cylinder->cyl_min < ty.d && ty.d < cylinder->cyl_max)
		ret.t.c = ty.b;
	intersect_caps(ray, cylinder, &ret);
	return (ret);
}

static int	abc_discri_calculating(t_3f *abc, double *discriminant, t_ray ray)
{
	abc->a = powf(ray.vector.x, 2) + powf(ray.vector.z, 2);
	if (equal_double(abc->a, 0))
		return (1);
	abc->b = 2 * ray.point.x * ray.vector.x + 2 * ray.point.z * ray.vector.z;
	abc->c = powf(ray.point.x, 2) + powf(ray.point.z, 2) - 1;
	*discriminant = powf(abc->b, 2) - 4 * abc->a * abc->c;
	if (*discriminant < 0)
		return (1);
	return (0);
}

static void	swap(double *a, double *b)
{
	double			stock;

	stock = *a;
	*a = *b;
	*b = stock;
}
