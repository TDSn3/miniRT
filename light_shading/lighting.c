/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/04 19:01:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Renvois une couleur													  */
/*                                                                            */
/*   effective_color = couleur de la surface + couleur de la lumiète		  */
/*   lightv 		 = trouve la direction de la source lumineuse			  */
/*   ambient         = contribution ambiante								  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	lighting(t_material material, t_light light, t_tuple point, t_tuple eyev_vector, t_tuple normalv_vector, int in_shadow)
{
	t_tuple	effective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	float	light_dot_normal;
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	refelctv;
	float	reflect_dot_eye;
	float	factor;

	effective_color = t_tuple_multi(material.color, light.intensity);
	lightv = t_tuple_minus(light.position, point);
	lightv = normalization_vector(lightv);
	ambient = t_tuple_multi_scal(effective_color, material.ambient);
	ambient = t_tuple_plus(ambient, material.a_color);
	light_dot_normal = scalar_product_vector(&lightv, &normalv_vector);
	if (light_dot_normal <= 0)
		return (ambient);
	diffuse = t_tuple_multi_scal(effective_color, material.diffuse * light_dot_normal);
	refelctv = reflect(t_tuple_nega(lightv), normalv_vector);
	reflect_dot_eye = scalar_product_vector(&refelctv, &eyev_vector);
	if (reflect_dot_eye <= 0)
		specular = (t_tuple){{0, 0, 0, 0}};
	else
	{
		factor = powf(reflect_dot_eye, material.shininess);
		specular = t_tuple_multi_scal(light.intensity, material.specular);
		specular = t_tuple_multi_scal(specular, factor);
	}
	if (in_shadow)
		return (ambient);
	else
		return (t_tuple_plus(t_tuple_plus(ambient, diffuse), specular));
}
