/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:08:53 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 11:01:37 by roberto          ###   ########.fr       */
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
#include "parser.h"

int	parse_sphere(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL_3, DECIMAL, BYTE_3};
	const void			targets[] = {&shape->center, &shape->radius,
		&shape->color};
	shape				*shape;

	shape = malloc(sizeof(*shape));
	if (!shape)
		return (NULL);
	shape->next = scene->shapes;
	if (parse_line(line, sizeof(syntax), syntax, shape) != sizeof(syntax))
		return (printf("Error\n", line), free(shape), NULL);
	return (NULL);
}

int	parse_plane(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL_3, DECIMAL_3, BYTE_3};
	shape				*shape;

	shape = malloc(sizeof(*shape));
	if (!shape)
		return (NULL);
	shape->next = scene->shapes;
	if (parse_line(line, sizeof(syntax), syntax, shape) != sizeof(syntax))
		return (printf("Error\n", line), free(shape), NULL);
	return (NULL);
}

int	parse_cylinder(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL_3, DECIMAL_3, DECIMAL, DECIMAL,
		BYTE_3};
	shape				*shape;

	shape = malloc(sizeof(*shape));
	if (!shape)
		return (NULL);
	shape->next = scene->shapes;
	if (parse_line(line, sizeof(syntax), syntax, shape) != sizeof(syntax))
		return (printf("Error\n", line), free(shape), NULL);
	return (NULL);
}
