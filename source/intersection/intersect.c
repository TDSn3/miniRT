/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:51:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 16:49:46 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static t_intersection	intersect_sphere(t_ray ray, t_object *sphere);
static double			give_discri(t_tuple vector,
							t_tuple point, t_object sphere, t_3f *abc);
static t_intersection	intersect_plane(t_ray ray, t_object *plane);

t_intersection	intersect(t_tuple vector, t_tuple point, t_object *object)
{
	t_ray			ray;

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
	t_3f			abc;
	double			discriminant;

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
		ret.t.b = (-abc.b - sqrt(discriminant)) / (2 * abc.a);
		ret.t.c = (-abc.b + sqrt(discriminant)) / (2 * abc.a);
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
static double	give_discri(t_tuple vector,
					t_tuple point, t_object sphere, t_3f *abc)
{
	double	discriminant;
	t_tuple	sphere_to_ray;

	sphere_to_ray = t_tuple_minus(point, sphere.position);
	abc->a = scalar_product_vector(&vector, &vector);
	abc->b = 2 * scalar_product_vector(&vector, &sphere_to_ray);
	abc->c = scalar_product_vector(&sphere_to_ray, &sphere_to_ray) - 1;
	discriminant = pow(abc->b, 2) - 4 * abc->a * abc->c;
	return (discriminant);
}

static t_intersection	intersect_plane(t_ray ray, t_object *plane)
{
	t_intersection	ret;
	double			t;

	ret.object = plane;
	ret.next = NULL;
	ret.prev = NULL;
	if ((ray.vector.y > EPSILON && ray.point.y > 0)
		|| (ray.vector.y < EPSILON && ray.point.y < 0))
	{
		ret.t.a = 0;
		ret.t.b = 0;
		ret.t.c = 0;
	}
	else
	{
		t = -ray.point.y / ray.vector.y;
		ret.t.a = 2;
		ret.t.b = t;
		ret.t.c = t;
	}
	return (ret);
}
