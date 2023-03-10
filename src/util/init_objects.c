/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 05:17:32 by roberto           #+#    #+#             */
/*   Updated: 2023/03/10 23:11:54 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <header.h>

void	init_common_params(t_object *object, t_parsed_object *parsed_object)
{
	t_tuple		position;
	t_matrix4	translation_mtx;

	object->material.color = (t_tuple){{parsed_object->color.b/255.0,
		parsed_object->color.r/255., parsed_object->color.r/255., 0}};
	position = (t_tuple){{parsed_object->position.x,
		parsed_object->position.y, parsed_object->position.z, 1}};
	translation(&position, &translation_mtx);
	multiply_matrix4(&translation_mtx, &object->transform, &object->transform);
	inverse_matrix4(&object->transform, &object->inverse);
}

void	init_sphere(t_object *object, t_parsed_object *parsed_object)
{
	t_matrix4	scale_mtx;

	printf("init sphere\n");
	scaling((t_tuple){{parsed_object->radius, parsed_object->radius,
		parsed_object->radius, 0}}, &scale_mtx);
	multiply_matrix4(&scale_mtx, &object->transform, &object->transform);
	inverse_matrix4(&object->transform, &object->inverse);
}

void	init_plane(t_object *object, t_parsed_object *parsed_object)
{
	printf("init plane\n");
	(void)object;
	(void)parsed_object;
	// TODO: get normal from parsed_objects and set transform matrix (rotate)
}

void	init_cylinder(t_object *object, t_parsed_object *parsed_object)
{
	printf("init cylinder\n");
	(void)object;
	(void)parsed_object;
	object->cyl_closed = 1;
	// TODO: get radius from parsed_objects and set transform matrix (scale)
	// TODO: get axis from parsed_objects and set transform matrix (rotate)
}

t_object	*init_objects(t_parsed_object *parsed_objects,
				t_parsed_ambient *parsed_ambient)
{
	t_object	*previous_object;
	t_object	*current_object;

	previous_object = NULL;
	current_object = NULL;
	while (parsed_objects)
	{
		current_object = object_lst_new(parsed_objects->type, parsed_ambient);
		if (!current_object)
			return (object_lst_clear(&previous_object), NULL);
		if (parsed_objects->type == SPHERE)
			init_sphere(current_object, parsed_objects);
		else if (parsed_objects->type == PLANE)
			init_plane(current_object, parsed_objects);
		else if (parsed_objects->type == CYLINDER)
			init_cylinder(current_object, parsed_objects);
		init_common_params(current_object, parsed_objects);
		current_object->next = previous_object;
		previous_object = current_object;
		parsed_objects = parsed_objects->next;
	}
	return (current_object);
}
