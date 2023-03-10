/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:47:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/10 22:28:10 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void	clean_line(char *line)
{
	while (*line)
	{
		if (*line >= '\t' && *line <= '\r')
			*line = ' ';
		line++;
	}
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

void	print_objects(t_parsed_scene const *scene)
{
	t_parsed_object	*objects;

	// printf("ambient: %f %d,%d,%d\n", scene.ambient.intensity, scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	// printf("camera: %f,%f,%f, %f,%f,%f %f\n", scene.camera.position.a, scene.camera.position.b, scene.camera.position.c, scene.camera.direction.a, scene.camera.direction.b, scene.camera.direction.c, scene.camera.fov_degrees);
	// printf("light: %f,%f,%f %f %d, %d, %d\n", scene.light.position.a, scene.light.position.b, scene.light.position.c, scene.light.intensity, scene.light.color.r, scene.light.color.g, scene.light.color.b);
	objects = scene->objects;
	while (objects)
	{
		if (objects->type == SPHERE)
			printf("\tsphere: %f,%f,%f %f %d,%d,%d\n", objects->position.x,
				objects->position.y, objects->position.z, objects->radius,
				objects->color.r, objects->color.g, objects->color.b);
		else if (objects->type == PLANE)
			printf("\tplane: %f,%f,%f %f,%f,%f %d,%d,%d\n", objects->position.x,
				objects->position.y, objects->position.z, objects->direction.x,
				objects->direction.y, objects->direction.z, objects->color.r,
				objects->color.g, objects->color.b);
		else if (objects->type == CYLINDER)
			printf("\tcylinder: %f,%f,%f %f,%f,%f %f %f %d,%d,%d\n",
				objects->position.x, objects->position.y, objects->position.z,
				objects->direction.x, objects->direction.y,
				objects->direction.z, objects->radius, objects->height,
				objects->color.r, objects->color.g, objects->color.b);
		objects = objects->next;
	}
}

void	free_objects(t_parsed_object *objects)
{
	t_parsed_object	*next;

	while (objects)
	{
		next = objects->next;
		free(objects);
		objects = next;
	}
}