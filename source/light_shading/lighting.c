/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 18:16:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Renvois une couleur													  */
/*                                                                            */
/*   effective_color = couleur de la surface + couleur de la lumiète		  */
/*   lightv 		 = trouve la direction de la source lumineuse			  */
/*   ambient         = contibution ambiante									  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev_vector, t_tuple nomralv_vector)
{
	t_tuple	effective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	float	light_dot_normal;
	t_tuple	diffuse;
//	t_tuple	specular;
	t_tuple	refelctv;

	effective_color = t_tuple_multi(material.color, light.intensity);
	lightv = t_tuple_minus(light.position, point);
	normalization_vector(&lightv);
	ambient = t_tuple_multi_scal(effective_color, material.ambient);
	light_dot_normal = scalar_product_vector(&lightv, &nomralv_vector);
	if (light_dot_normal < 0)
	{
		diffuse = (t_tuple){0};
//		specular = (t_tuple){0};
	}
	else
	{
		diffuse = t_tuple_multi_scal(t_tuple_multi_scal(effective_color, material.diffuse), light_dot_normal);
//		refelctv = reflect();
	}
	retrun (t_tuple_plus(ambient, diffuse));
}
