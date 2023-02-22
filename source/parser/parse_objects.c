/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:08:53 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/22 22:12:04 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:43 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/19 19:10:12 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*parse_sphere(t_world *scene, char *line)
{
	(void)scene;
	(void)line;
	// t_shape	*shape;
	// shape = malloc(sizeof(*shape));
	// if (!shape)
	// 	return (1);
	// shape->next = scene->shapes;
	// if (sscanf(line, "sp %lf,%lf,%lf %lf %hhu,%hhu,%hhu", &shape->position.x,
	// 		&shape->position.y, &shape->position.z, &shape->radius,
	// 		&shape->color.r, &shape->color.g, &shape->color.b) != 7)
	// 	return (printf("Error: Invalid sphere\n"), free(shape), 1);
	// shape->radius /= 2;
	// printf("color: %hhu %hhu %hhu\n", shape->color.r, shape->color.g,
	// 		shape->color.b);
	// perror("sphere");
	// shape->type = SPHERE;
	// scene->shapes = shape;
	return (NULL);
}

char	*parse_plane(t_world *scene, char *line)
{
	(void)scene;
	(void)line;
	// t_shape	*shape;
	// shape = malloc(sizeof(*shape));
	// if (!shape)
	// 	return (1);
	// shape->next = scene->shapes;
	// if (sscanf(line, "pl %lf,%lf,%lf %lf,%lf,%lf %hhu,%hhu,%hhu",
	// 		&shape->position.x, &shape->position.y, &shape->position.z,
	// 		&shape->direction.x, &shape->direction.y, &shape->direction.z,
	// 		&shape->color.r, &shape->color.g, &shape->color.b) != 9)
	// 	return (printf("Error: Invalid plane\n"), free(shape), 1);
	// perror("plane");
	// shape->type = PLANE;
	// scene->shapes = shape;
	return (NULL);
}

char	*parse_cylinder(t_world *scene, char *line)
{
	(void)scene;
	(void)line;
	// t_shape	*shape;
	// shape = malloc(sizeof(*shape));
	// if (!shape)
	// 	return (1);
	// shape->next = scene->shapes;
	// if (sscanf(line, "cy %lf,%lf,%lf %lf,%lf,%lf %lf %lf %hhu,%hhu,%hhu",
	// 		&shape->position.x, &shape->position.y, &shape->position.z,
	// 		&shape->direction.x, &shape->direction.y, &shape->direction.z,
	// 		&shape->radius, &shape->height, &shape->color.r, &shape->color.g,
	// 		&shape->color.b) != 11)
	// 	return (printf("Error: Invalid cylinder\n"), free(shape), 1);
	// perror("cylinder");
	// shape->radius /= 2;
	// shape->type = CYLINDER;
	// scene->shapes = shape;
	return (NULL);
}
