/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:51:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 15:54:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static t_intersection	intersect_sphere(t_ray ray, t_object *sphere);
static float			give_discri(t_tuple vector,
							t_tuple point, t_object sphere, t_3f *abc);
static t_intersection	intersect_plane(t_ray ray, t_object *plane);
static t_intersection	intersect_cylinder(t_ray ray, t_object *cylinder);


t_intersection	intersect(t_tuple vector, t_tuple point, t_object *object)
{
	t_ray			ray;
	t_matrix4		inv_mtx;

	inverse_matrix4(object->transform, &inv_mtx);
	ray = transform_ray(vector, point, &inv_mtx);
	if (object->type == SPHERE)
		return (intersect_sphere(ray, object));
	else if (object->type == PLANE)
		return (intersect_plane(ray, object));
	else
		return (intersect_cylinder(ray, object));
}

/* ************************************************************************** */
/*                                                                            */
/*   vector + point = rayon													  */
/*                                                                            */
/*   Supposons que l'origine d'une sphère est située à l'origine		  	  */
/*   du monde (0, 0, 0). Nous supposerons également que ce soit une sphère    */
/*   unitaire, avec un rayons de 1.								  			  */
/*                                                                            */
/* ************************************************************************** */
static t_intersection	intersect_sphere(t_ray ray, t_object *sphere)
{
	t_intersection	ret;
	t_3f			abc;
	float			discriminant;

	ret.object = sphere;
	ret.next = NULL;
	ret.prev = NULL;
	discriminant = give_discri(ray.vector, ray.point, *sphere, &abc);
	if (discriminant < 0)
	{
		ret.t.a = 0;
		ret.t.b = 0;
		ret.t.c = 0;
	}
	else
	{
		ret.t.a = 2;
		ret.t.b = (-abc.b - sqrtf(discriminant)) / (2 * abc.a);
		ret.t.c = (-abc.b + sqrtf(discriminant)) / (2 * abc.a);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*   vector   direction du rayon											  */
/*   point    position de l'origine du rayon								  */
/*                                                                            */
/*   sphere_to_ray = point - sphere.position                                  */
/*                                                                            */
/*   abc->a = (produit scalaire de vector et vector)                          */
/*   abc->b = 2 * (produit scalaire de vector et sphere_to_ray)               */
/*   abc->c = (produit scalaire de sphere_to_ray et sphere_to_ray) -1         */
/*                                                                            */
/* ************************************************************************** */
static float	give_discri(t_tuple vector,
					t_tuple point, t_object sphere, t_3f *abc)
{
	float	discriminant;
	t_tuple	sphere_to_ray;

	sphere_to_ray = t_tuple_minus(point, sphere.position);
	abc->a = scalar_product_vector(&vector, &vector);
	abc->b = 2 * scalar_product_vector(&vector, &sphere_to_ray);
	abc->c = scalar_product_vector(&sphere_to_ray, &sphere_to_ray) - 1;
	discriminant = powf(abc->b, 2) - 4 * abc->a * abc->c;
	return (discriminant);
}

static t_intersection	intersect_plane(t_ray ray, t_object *plane)
{
	t_intersection	ret;
	float			stock;

	ret.object = plane;
	ret.next = NULL;
	ret.prev = NULL;
	if (ray.vector.y < EPSILON)
	{
		ret.t.a = 0;
		ret.t.b = 0;
		ret.t.c = 0;
	}
	else
	{
		stock = ray.point.y / ray.vector.y;
		if (stock < 0)
			stock *= -1; // ATTENTION
		ret.t.a = 1;
		ret.t.b = stock;
		ret.t.c = 0;
	}
	return (ret);
}

static t_intersection	intersect_cylinder(t_ray ray, t_object *cylinder)
{
	t_intersection	ret;
	t_3f			abc;
	float			discriminant;
	float			stock;
	float			y0;
	float			y1;

	ret.object = cylinder;
	ret.next = NULL;
	ret.prev = NULL;
	ret.t.a = 0;
	ret.t.b = 0;
	ret.t.c = 0;
	abc.a = powf(ray.vector.x, 2) + powf(ray.vector.z, 2);
	if (equal_float(abc.a, 0))
	{
		ret.t.a = 0;
		ret.t.b = 0;
		ret.t.c = 0;
		return (ret);
	}
	abc.b = 2 * ray.point.x * ray.vector.x + 2 * ray.point.z * ray.vector.z;
	abc.c = powf(ray.point.x, 2) + powf(ray.point.z, 2) - 1;
	discriminant = powf(abc.b, 2) - 4 * abc.a * abc.c;
	if (discriminant < 0)
	{
		ret.t.a = 0;
		ret.t.b = 0;
		ret.t.c = 0;
		return (ret);
	}
	ret.t.a = 2;
	ret.t.b = (-abc.b - sqrtf(discriminant)) / (2 * abc.a);
	ret.t.c = (-abc.b + sqrtf(discriminant)) / (2 * abc.a);
	if (ret.t.b > ret.t.c)
	{
		stock = ret.t.b;
		ret.t.b = ret.t.c;
		ret.t.c = stock;
	}
	y0 = ray.point.y + ret.t.b * ray.vector.y;
	if (!(cylinder->cyl_min < y0 && y0 < cylinder->cyl_max))
	{
		ret.t.b = 0;
		ret.t.a--;
	}
	y1 = ray.point.y + ret.t.c * ray.vector.y;
	if (!(cylinder->cyl_min < y1 && y1 < cylinder->cyl_max))
	{
		ret.t.c = 0;
		ret.t.a--;
	}
	intersect_caps(ray, cylinder, &ret);
	return (ret);
}
