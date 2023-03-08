/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:51:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:03:41 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static t_intersection	intersect_sphere(t_ray ray, t_object *sphere);
static float			give_discri(t_tuple vector,
							t_tuple point, t_object sphere, float abc[3]);
static t_intersection	intersect_plane(t_ray ray, t_object *plane);
static t_intersection	intersect_cylinder(t_ray ray, t_object *cylinder);
static void				swap(float *a, float *b);


t_intersection	intersect(t_tuple vector, t_tuple point, t_object *object)
{
	t_ray			ray;
	// t_matrix4		inv_mtx;

	// inverse_matrix4(&object->transform, &inv_mtx);
	ray = transform_ray(vector, point, &object->inverse);
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
	float			abc[3];
	float			discriminant;

	ret.object = sphere;
	ret.next = NULL;
	ret.prev = NULL;
	discriminant = give_discri(ray.vector, ray.point, *sphere, abc);
	if (discriminant < 0)
	{
		ret.t[0] = 0;
		ret.t[1] = 0;
		ret.t[2] = 0;
	}
	else
	{
		ret.t[0] = 2;
		ret.t[1] = (-abc[1] - sqrtf(discriminant)) / (2 * abc[0]);
		ret.t[2] = (-abc[1] + sqrtf(discriminant)) / (2 * abc[0]);
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
					t_tuple point, t_object sphere, float abc[3])
{
	float	discriminant;
	t_tuple	sphere_to_ray;

	sphere_to_ray = t_tuple_minus(point, sphere.position);
	abc[0] = scalar_product_vector(&vector, &vector);
	abc[1] = 2 * scalar_product_vector(&vector, &sphere_to_ray);
	abc[2] = scalar_product_vector(&sphere_to_ray, &sphere_to_ray) - 1;
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	return (discriminant);
}

static t_intersection	intersect_plane(t_ray ray, t_object *plane)
{
	t_intersection	ret;
	float			t;

	ret.object = plane;
	ret.next = NULL;
	ret.prev = NULL;
	if (ray.vector.y < EPSILON)
	{
		ret.t[0] = 0;
		ret.t[1] = 0;
		ret.t[2] = 0;
	}
	else
	{
		t = -ray.point.y / ray.vector.y;
		ret.t[0] = 2;
		ret.t[1] = t;
		ret.t[2] = 0;
	}
	return (ret);
}

static t_intersection	intersect_cylinder(t_ray ray, t_object *cylinder)
{
	t_intersection	ret;
	float			abc[3];
	float			discriminant;
	float			t0;
	float			t1;
	float			y0;
	float			y1;

	ret.object = cylinder;
	ret.next = NULL;
	ret.prev = NULL;
	ret.t[0] = 0;
	ret.t[1] = 0;
	ret.t[2] = 0;
	// abc[0] = powf(ray.vector.x, 2) + powf(ray.vector.z, 2);
	abc[0] = ray.vector.x * ray.vector.x + ray.vector.z * ray.vector.z;
	if (equal_float(abc[0], 0))
		return (ret);
	abc[1] = 2 * ray.point.x * ray.vector.x + 2 * ray.point.z * ray.vector.z;
	// abc[2] = powf(ray.point.x, 2) + powf(ray.point.z, 2) - 1;
	abc[2] = ray.point.x * ray.point.x + ray.point.z * ray.point.z - 1;
	// discriminant = powf(abc[1], 2) - 4 * abc[0] * abc[2];
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (ret);
	ret.t[0] = 2;
	t0 = (-abc[1] - sqrtf(discriminant)) / (2 * abc[0]);
	t1 = (-abc[1] + sqrtf(discriminant)) / (2 * abc[0]);
	if (t0 > t1)
		swap(&t0, &t1);
	y0 = ray.point.y + t0 * ray.vector.y;
	if (cylinder->cyl_min < y0 && y0 < cylinder->cyl_max)
		ret.t[1] = t0;
	y1 = ray.point.y + t1 * ray.vector.y;
	if (cylinder->cyl_min < y1 && y1 < cylinder->cyl_max)
		ret.t[2] = t1;
	intersect_caps(ray, cylinder, &ret);
	return (ret);
}

static void	swap(float *a, float *b)
{
	float			stock;

	stock = *a;
	*a = *b;
	*b = stock;
}
