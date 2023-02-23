/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:51:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 00:35:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static float	give_discri(t_tuple vector,
					t_tuple point, t_object sphere, t_3f *abc);

/* ************************************************************************** */
/*                                                                            */
/*   vector + point = rayon													  */
/*                                                                            */
/*   Supposons que l'origine d'une sphère est située à l'origine		  	  */
/*   du monde (0, 0, 0). Nous supposerons également que ce soit une sphère    */
/*   unitaire, avec un rayons de 1.								  			  */
/*                                                                            */
/* ************************************************************************** */
t_intersection	intersect(t_tuple vector, t_tuple point, t_object *sphere)
{
	t_intersection	ret;
	t_3f			abc;
	t_ray			ray;
	t_matrix4		inv_mtx;
	float			discriminant;

	ret.object = sphere;
	inverse_matrix4(sphere->transform, &inv_mtx);
	ray = transform_ray(vector, point, &inv_mtx);
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
	ret.next = NULL;
	ret.prev = NULL;
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
