/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:01:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 14:13:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	init_object(t_all_data *all_data, t_dp *data_parsing)
{
	t_parsed_object	*cpy;
	t_object		*last_object;

	cpy = all_data->parsed_scene->objects;
	while (cpy)
	{
		printf("%sNew object", COLOR_BOLD_MAGENTA);
		if (so_add_back(&all_data->list_object, so_new(
					cpy->type, *data_parsing)))
			return (1);
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
	return (0);
}
