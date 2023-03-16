/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:33:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 13:45:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_matrix(t_dp *data_parsing, t_camera *c);

void	init_camera(t_all_data *all_data, t_dp *data_parsing, t_camera *c)
{
	data_parsing->c_position.x = all_data->parsed_scene->camera.position.x
		+ all_data->data_key->c_add_pos_x;
	data_parsing->c_position.y = all_data->parsed_scene->camera.position.y
		+ all_data->data_key->c_add_pos_y;
	data_parsing->c_position.z = all_data->parsed_scene->camera.position.z
		+ all_data->data_key->c_add_pos_z;
	data_parsing->c_to.x = all_data->parsed_scene->camera.direction.x
		+ all_data->data_key->c_add_to_x;
	data_parsing->c_to.y = all_data->parsed_scene->camera.direction.y
		+ all_data->data_key->c_add_to_y;
	data_parsing->c_to.z = all_data->parsed_scene->camera.direction.z
		+ all_data->data_key->c_add_to_z;
	data_parsing->c_fov = deg_to_rad(all_data->parsed_scene->camera.fov_degrees
			+ all_data->data_key->c_add_fov);
	*c = give_camera(HEIGHT, WIDHT, data_parsing->c_fov);
	init_matrix(data_parsing, c);
	inverse_matrix4(c->transform, &c->inverse);
}

static void	init_matrix(t_dp *data_parsing, t_camera *c)
{
	c->transform = view_transform(
			(t_tuple){{
			data_parsing->c_position.x,
			data_parsing->c_position.y,
			data_parsing->c_position.z,
			1
		}},
			(t_tuple){{
			data_parsing->c_to.x,
			data_parsing->c_to.y,
			data_parsing->c_to.z,
			0
		}},
			(t_tuple){{
			0,
			1,
			0,
			0
		}});
}
