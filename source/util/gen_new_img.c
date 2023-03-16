/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:47:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 10:04:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	test(t_all_data *all_data);

int	gen_new_img(t_all_data *all_data)
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;

	if (all_data->gen_img)
	{
		data_img = all_data->data_img;
		mwi = all_data->mwi;
		data_img -> img = mlx_new_image(mwi -> mlx, 1080, 720);
		data_img -> addr = mlx_get_data_addr(
				mwi -> data_img -> img,
				&mwi -> data_img -> bits_per_pixel,
				&mwi -> data_img -> line_length,
				&mwi -> data_img -> endian);

//	pixel_put ***********************************************************************

		test(all_data);

// //	*********************************************************************************

 		mlx_put_image_to_window(
 			mwi -> mlx,
 			mwi -> win,
 			mwi -> data_img -> img,
 			0,
 			0);
 		mlx_destroy_image(mwi -> mlx, mwi -> data_img -> img);
 		mwi -> data_img -> img = NULL;
		all_data->gen_img = 0;
		printf("%sNew image%s\n", COLOR_BOLD_YELLOW, COLOR_RESET);
	}
	return (0);
}

static void	test(t_all_data *all_data)
{
	t_world		w;
	t_camera	c;
	t_light		light;
	t_dp		data_parsing;

/* ************************************************************************** */
/*   Lumière ambiante   A   0.2   255,255,255                                 */
/* ************************************************************************** */
	data_parsing.ambient = all_data->parsed_scene->ambient.intensity;

	data_parsing.a_color.x = conv_color(
			all_data->parsed_scene->ambient.color.r) * data_parsing.ambient;
	data_parsing.a_color.y = conv_color(
			all_data->parsed_scene->ambient.color.g) * data_parsing.ambient;
	data_parsing.a_color.z = conv_color(
			all_data->parsed_scene->ambient.color.b) * data_parsing.ambient;
	data_parsing.a_color.w = 0;

/* ************************************************************************** */
/*   Camera   C   0,0,20.6   0,0,1   70		                                  */
/* ************************************************************************** */
	data_parsing.c_position.x = all_data->parsed_scene->camera.position.x
		+ all_data->data_key->c_add_pos_x;
	data_parsing.c_position.y = all_data->parsed_scene->camera.position.y
		+ all_data->data_key->c_add_pos_y;
	data_parsing.c_position.z = all_data->parsed_scene->camera.position.z
		+ all_data->data_key->c_add_pos_z;

	data_parsing.c_to.x = all_data->parsed_scene->camera.direction.x
		+ all_data->data_key->c_add_to_x;
	data_parsing.c_to.y = all_data->parsed_scene->camera.direction.y
		+ all_data->data_key->c_add_to_y;
	data_parsing.c_to.z = all_data->parsed_scene->camera.direction.z
		+ all_data->data_key->c_add_to_z;

	data_parsing.c_fov = deg_to_rad(all_data->parsed_scene->camera.fov_degrees
		+ all_data->data_key->c_add_fov);

	c = give_camera(HEIGHT, WIDHT, data_parsing.c_fov);
	c.transform = view_transform(
			(t_tuple){{data_parsing.c_position.x, data_parsing.c_position.y, data_parsing.c_position.z, 1}},
			(t_tuple){{data_parsing.c_to.x, data_parsing.c_to.y, data_parsing.c_to.z, 0}},
			(t_tuple){{0, 1, 0, 0}});
	inverse_matrix4(c.transform, &c.inverse);

/* ************************************************************************** */
/*   Lumière   L   0,0,20.6   0.6   10,0,255	  	                          */
/* ************************************************************************** */
	data_parsing.l_position.x = all_data->parsed_scene->light.position.x;
	data_parsing.l_position.y = all_data->parsed_scene->light.position.y;
	data_parsing.l_position.z = all_data->parsed_scene->light.position.z;

	data_parsing.l_i = all_data->parsed_scene->light.intensity;

	data_parsing.l_color.x = conv_color(all_data->parsed_scene->light.color.r);
	data_parsing.l_color.y = conv_color(all_data->parsed_scene->light.color.g);
	data_parsing.l_color.z = conv_color(all_data->parsed_scene->light.color.b);

	light.position = (t_tuple){{data_parsing.l_position.x, data_parsing.l_position.y, data_parsing.l_position.z, 1}};
	light.intensity = (t_tuple){{data_parsing.l_i, data_parsing.l_i, data_parsing.l_i, 0}};
	w.light = light;



	t_parsed_object *cpy;
	t_object		*last_object;

	cpy = all_data->parsed_scene->objects;
	while (cpy)
	{
		printf("%sNew object", COLOR_BOLD_MAGENTA);
		if (so_add_back(&all_data->list_object, so_new(cpy->type, data_parsing)))
			return ; // a compléter
		last_object = so_last(all_data->list_object);
		if (!last_object)
			continue ;
		if (cpy->type == SPHERE)
		{
			printf(" SPHERE%s\n", COLOR_RESET);
			last_object->transform = multiply_matrix4(
					translation((t_tuple){{
						cpy->position.x, cpy->position.y, cpy->position.z, 0}}),
					scaling((t_tuple){{
						cpy->radius, cpy->radius, cpy->radius, 0}}));
			inverse_matrix4(last_object->transform, &last_object->inverse);
		}
		else if (cpy->type == PLANE)
		{
			printf(" PLANE%s\n", COLOR_RESET);
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_x(cpy->direction.x));
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_y(cpy->direction.y));
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_z(cpy->direction.z));
			last_object->transform = multiply_matrix4(last_object->transform,
					translation((t_tuple){{cpy->position.x,
						cpy->position.y, cpy->position.z, 0}}));
			inverse_matrix4(last_object->transform, &last_object->inverse);
			last_object->material.specular = 0.1;
		}
		else
		{
			printf(" CYLINDER%s\n", COLOR_RESET);
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_x(cpy->direction.x));
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_y(cpy->direction.y));
			last_object->transform = multiply_matrix4(
					last_object->transform, rotation_z(cpy->direction.z));
			last_object->transform = multiply_matrix4(
					last_object->transform, scaling((t_tuple){{
						cpy->radius, cpy->radius, cpy->radius, 0}}));
			last_object->transform = multiply_matrix4(last_object->transform,
					translation((t_tuple){{cpy->position.x,
						cpy->position.y, cpy->position.z, 0}}));
			inverse_matrix4(last_object->transform, &last_object->inverse);
			last_object->cyl_max = cpy->height / 2;
			last_object->cyl_min = cpy->height / 2 * -1;
			last_object->cyl_closed = 1;
		}
		last_object->material.color = (t_tuple){{
			conv_color(cpy->color.r),
			conv_color(cpy->color.g),
			conv_color(cpy->color.b), 0}};
		cpy = cpy->next;
	}



	w.lst_object = all_data->list_object;
	render(all_data, c, &w);
	so_clear(&all_data->list_object);
	all_data->list_object = NULL;
	printf("%sEnd of test()%s\n", COLOR_BLUE, COLOR_RESET);
}
