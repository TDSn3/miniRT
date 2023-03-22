/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 09:56:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static double	fade_distance(t_comps comps);
static t_tuple	specular(t_tuple lightv, t_comps comps, t_light light);

/* ************************************************************************** */
/*                                                                            */
/*   Renvois une couleur													  */
/*                                                                            */
/*   effective_col = couleur de la surface + couleur de la lumiète			  */
/*   lightv 		 = trouve la direction de la source lumineuse			  */
/*   ambient         = contribution ambiante								  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	lighting(t_comps comps, t_light light, int in_shadow)
{
	t_tuple	effective_col;
	t_tuple	lightv;
	t_tuple	ambient;
	double	light_dot_normal;
	t_tuple	diffuse;

	lightv = t_tuple_minus(light.position, comps.over_point);
	lightv = normalization_vector(lightv);
	light_dot_normal = scalar_product_vector(&lightv, &comps.normalv_vector);
	effective_col = t_tuple_multi(comps.object.material.color, light.intensity);
	ambient = t_tuple_multi_scal(effective_col, comps.object.material.ambient);
	ambient = t_tuple_plus(ambient, comps.object.material.a_color);
	light.intensity = t_tuple_multi_scal(light.intensity, fade_distance(comps));
	effective_col = t_tuple_multi(comps.object.material.color, light.intensity);
	if (light_dot_normal <= EPSILON || in_shadow)
		return (ambient);
	diffuse = t_tuple_multi_scal(
			effective_col, comps.object.material.diffuse * light_dot_normal);
	return (t_tuple_plus(
			t_tuple_plus(ambient, diffuse), specular(lightv, comps, light)));
}

static double	fade_distance(t_comps comps)
{
	double	constant_factor;
	double	linear_factor;
	double	quadratic_factor;
	double	attenuation_factor;

	constant_factor = 20;
	linear_factor = 0.07;
	quadratic_factor = 0.0001;
	attenuation_factor = 30 / (constant_factor
			+ linear_factor
			* comps.distance
			+ quadratic_factor
			* comps.distance
			* comps.distance);
	return (attenuation_factor);
}

static t_tuple	specular(t_tuple lightv, t_comps comps, t_light light)
{
	double	factor;
	t_tuple	refelctv;
	double	reflect_dot_eye;
	t_tuple	specular_ret;

	refelctv = reflect(t_tuple_nega(lightv), comps.normalv_vector);
	reflect_dot_eye = scalar_product_vector(&refelctv, &comps.eyev_vector);
	if (reflect_dot_eye <= 0)
		specular_ret = (t_tuple){{0, 0, 0, 0}};
	else
	{
		factor = powf(reflect_dot_eye, comps.object.material.shininess);
		specular_ret = t_tuple_multi_scal(
				light.intensity, comps.object.material.specular);
		specular_ret = t_tuple_multi_scal(specular_ret, factor);
	}
	return (specular_ret);
}
