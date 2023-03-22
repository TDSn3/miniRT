/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:51:29 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/19 09:44:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_light(
	t_all_data *all_data,
	t_dp *data_parsing,
	t_light *light,
	t_world *w)
{
	data_parsing->l_position.x = all_data->parsed_scene->light.position.x;
	data_parsing->l_position.y = all_data->parsed_scene->light.position.y;
	data_parsing->l_position.z = all_data->parsed_scene->light.position.z;
	data_parsing->l_i = all_data->parsed_scene->light.intensity;
	data_parsing->l_color.x
		= conv_color(all_data->parsed_scene->light.color.r);
	data_parsing->l_color.y
		= conv_color(all_data->parsed_scene->light.color.g);
	data_parsing->l_color.z
		= conv_color(all_data->parsed_scene->light.color.b);
	light->position = (t_tuple){{
		data_parsing->l_position.x,
		data_parsing->l_position.y,
		data_parsing->l_position.z,
		1}};
	light->intensity = (t_tuple){{
		data_parsing->l_i,
		data_parsing->l_i,
		data_parsing->l_i,
		0}};
	w->light = *light;
}
