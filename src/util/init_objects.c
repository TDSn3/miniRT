/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 05:17:32 by roberto           #+#    #+#             */
/*   Updated: 2023/03/10 07:16:16 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <header.h>

void	init_common_params(t_object *object, t_parsed_object *parsed_object,
				t_parsed_ambient *parsed_ambient)
{
	*object = (t_object){};
	object->type = parsed_object->type;
	object->position = (t_tuple){{parsed_object->position.x,
		parsed_object->position.y, parsed_object->position.z, 1}};
	// TODO: get position from parsed_objects and set transform matrix (translate)
	identity_matrix(4, (double *)&object->transform);
	inverse_matrix4(&object->transform, &object->inverse);
	// TODO: get ambient light from parsed_ambient and set material
	(void)parsed_ambient;
}

void	init_sphere(t_object *object, t_parsed_object *parsed_object)
{
	printf("init sphere\n");
	(void)object;
	(void)parsed_object;
	// TODO: get radius from parsed_objects and set transform matrix (scale)
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
		current_object = malloc(sizeof(*current_object));
		if (!current_object)
			return (object_lst_clear(&previous_object), NULL);
		if (parsed_objects->type == SPHERE)
			init_sphere(current_object, parsed_objects);
		else if (parsed_objects->type == PLANE)
			init_plane(current_object, parsed_objects);
		else if (parsed_objects->type == CYLINDER)
			init_cylinder(current_object, parsed_objects);
		init_common_params(current_object, parsed_objects, parsed_ambient);
		current_object->next = previous_object;
		previous_object = current_object;
		parsed_objects = parsed_objects->next;
	}
	free_objects(parsed_objects);
	return (current_object);
}
