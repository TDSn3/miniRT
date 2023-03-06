/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 02:43:21 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 07:12:28 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

char	*parse_sphere(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC, COLOR};
	void				*params[sizeof(syntax) / sizeof(*syntax)];
	t_parsed_object		*sphere;

	sphere = malloc(sizeof(t_parsed_object));
	if (!sphere)
		return (free_tokens(--tokens), "Malloc failed (sp)");
	params[0] = &sphere->position;
	params[1] = &sphere->radius;
	params[2] = &sphere->color;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), free(sphere), "Invalid sphere syntax");
	sphere->type = SPHERE;
	sphere->radius /= 2;
	sphere->next = scene->objects;
	scene->objects = sphere;
	return (free_tokens(--tokens), NULL);
}

char	*parse_plane(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, COLOR};
	void				*params[sizeof(syntax) / sizeof(*syntax)];
	t_parsed_object		*plane;

	plane = malloc(sizeof(t_parsed_object));
	if (!plane)
		return (free_tokens(--tokens), free(plane), "Malloc failed (pl)");
	params[0] = &plane->position;
	params[1] = &plane->direction;
	params[2] = &plane->color;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), "Invalid plane syntax");
	plane->type = PLANE;
	plane->next = scene->objects;
	scene->objects = plane;
	return (free_tokens(--tokens), NULL);
}

char	*parse_cylinder(t_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, DEC, DEC, COLOR};
	void				*params[sizeof(syntax) / sizeof(*syntax)];
	t_parsed_object		*cylinder;

	cylinder = malloc(sizeof(t_parsed_object));
	if (!cylinder)
		return (free_tokens(--tokens), free(cylinder), "Malloc failed (cy)");
	params[0] = &cylinder->position;
	params[1] = &cylinder->direction;
	params[2] = &cylinder->radius;
	params[3] = &cylinder->height;
	params[4] = &cylinder->color;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), "Invalid cylinder syntax");
	cylinder->type = CYLINDER;
	cylinder->radius /= 2;
	cylinder->next = scene->objects;
	scene->objects = cylinder;
	return (free_tokens(--tokens), NULL);
}
