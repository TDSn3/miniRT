/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:01:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 17:10:41 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_sphere(t_parsed_object *cpy, t_object *last_object);
static void	init_cylinder(t_parsed_object *cpy, t_object *last_object);
static void	init_plane(t_parsed_object *cpy, t_object *last_object);

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
			init_sphere(cpy, last_object);
		else if (cpy->type == PLANE)
			init_plane(cpy, last_object);
		else
			init_cylinder(cpy, last_object);
		last_object->material.color = (t_tuple){{conv_color(cpy->color.r),
			conv_color(cpy->color.g), conv_color(cpy->color.b), 0}};
		cpy = cpy->next;
	}
	return (0);
}

static void	init_sphere(t_parsed_object *cpy, t_object *last_object)
{
	printf(" SPHERE%s\n", COLOR_RESET);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{cpy->radius, 0, 0, 0},
	{0, cpy->radius, 0, 0},
	{0, 0, cpy->radius, 0},
	{0, 0, 0, 1}}},last_object->transform);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{1, 0, 0, cpy->position.x},
	{0, 1, 0, cpy->position.y},
	{0, 0, 1, cpy->position.z},
	{0, 0, 0, 1}}},last_object->transform);
	inverse_matrix4(last_object->transform, &last_object->inverse);
}

t_tuple	get_non_parallel(t_tuple vector)
{
	t_tuple	non_parallel;

	if (fabs(vector.x) >= fabs(vector.y) && fabs(vector.x) >= fabs(vector.z))
		non_parallel = (t_tuple){{0, 1, 0, 0}};
	else if (fabs(vector.y) >= fabs(vector.x)
		&& fabs(vector.y) >= fabs(vector.z))
		non_parallel = (t_tuple){{1, 0, 0, 0}};
	else
		non_parallel = (t_tuple){{0, 1, 0, 0}};
	return (non_parallel);
}

static void	init_plane(t_parsed_object *cpy, t_object *last_object)
{
	t_tuple	vertical;
	t_tuple	horizontal_1;
	t_tuple	horizontal_2;

	vertical = (t_tuple){{cpy->direction.x, cpy->direction.y,
		cpy->direction.z, 0}};
	vertical = normalization_vector(vertical);
	horizontal_1 = get_non_parallel(vertical);
	horizontal_2 = cross_product_vector(vertical, horizontal_1);
	horizontal_1 = cross_product_vector(horizontal_2, vertical);
	last_object->transform = multiply_matrix4((t_matrix4){{
	{horizontal_1.x, vertical.x, horizontal_2.x, 0},
	{horizontal_1.y, vertical.y, horizontal_2.y, 0},
	{horizontal_1.z, vertical.z, horizontal_2.z, 0},
	{0, 0, 0, 1}
	}}, last_object->transform);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{1, 0, 0, cpy->position.x},
	{0, 1, 0, cpy->position.y},
	{0, 0, 1, cpy->position.z},
	{0, 0, 0, 1}}},last_object->transform);
	inverse_matrix4(last_object->transform, &last_object->inverse);
	last_object->material.specular = 0.1;
}

static void	init_cylinder(t_parsed_object *cpy, t_object *last_object)
{
	t_tuple	vertical;
	t_tuple	horizontal_1;
	t_tuple	horizontal_2;

	vertical = (t_tuple){{cpy->direction.x, cpy->direction.y,
		cpy->direction.z, 0}};
	vertical = normalization_vector(vertical);
	horizontal_1 = get_non_parallel(vertical);
	horizontal_2 = cross_product_vector(vertical, horizontal_1);
	horizontal_1 = cross_product_vector(horizontal_2, vertical);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{cpy->radius, 0, 0, 0},
	{0, cpy->height/2, 0, 0},
	{0, 0, cpy->radius, 0},
	{0, 0, 0, 1}}},last_object->transform);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{horizontal_1.x, vertical.x, horizontal_2.x, 0},
	{horizontal_1.y, vertical.y, horizontal_2.y, 0},
	{horizontal_1.z, vertical.z, horizontal_2.z, 0},
	{0, 0, 0, 1}}}, last_object->transform);
	last_object->transform = multiply_matrix4(
	(t_matrix4){{
	{1, 0, 0, cpy->position.x},
	{0, 1, 0, cpy->position.y},
	{0, 0, 1, cpy->position.z},
	{0, 0, 0, 1}}},last_object->transform);
	inverse_matrix4(last_object->transform, &last_object->inverse);
	last_object->cyl_closed = 1;
}

// static void	init_sphere(t_parsed_object *cpy, t_object *last_object)
// {
// 	printf(" SPHERE%s\n", COLOR_RESET);
// 	last_object->transform = multiply_matrix4(
// 			translation((t_tuple){{
// 				cpy->position.x, cpy->position.y, cpy->position.z, 0}}),
// 			scaling((t_tuple){{
// 				cpy->radius, cpy->radius, cpy->radius, 0}}));
// 	inverse_matrix4(last_object->transform, &last_object->inverse);
// }

// static void	init_plane(t_parsed_object *cpy, t_object *last_object)
// {
// 	printf(" PLANE%s\n", COLOR_RESET);
// 	last_object->transform = multiply_matrix4(last_object->transform,
// 			translation((t_tuple){{cpy->position.x,
// 				cpy->position.y, cpy->position.z, 0}}));
// 	last_object->transform = multiply_matrix4(
// 			last_object->transform, rotation_x(rad_to_deg(asin(cpy->direction.y))));
// 	last_object->transform = multiply_matrix4(
// 			last_object->transform, rotation_y(rad_to_deg(atan2(cpy->direction.x, cpy->direction.z))));
// 	inverse_matrix4(last_object->transform, &last_object->inverse);
// 	last_object->material.specular = 0.1;
// }

// static void	init_cylinder(t_parsed_object *cpy, t_object *last_object)
// {
// 	printf(" CYLINDER%s\n", COLOR_RESET);
// 	last_object->transform = multiply_matrix4(last_object->transform,
// 			translation((t_tuple){{cpy->position.x,
// 				cpy->position.y, cpy->position.z, 0}}));
// 	printf("%f\n", cpy->radius);
// 	last_object->transform = multiply_matrix4(
// 			last_object->transform, rotation_x(rad_to_deg(asin(cpy->direction.y))));
// 	last_object->transform = multiply_matrix4(
// 			last_object->transform, rotation_y(rad_to_deg(atan2(cpy->direction.x, cpy->direction.z))));
// 	last_object->transform = multiply_matrix4(
// 			last_object->transform, diameter_cylinder(cpy->radius));
// 	inverse_matrix4(last_object->transform, &last_object->inverse);
// 	last_object->cyl_max = cpy->height / 2;
// 	last_object->cyl_min = cpy->height / 2 * -1;
// 	last_object->cyl_closed = 1;
// }
