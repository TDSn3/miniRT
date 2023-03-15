/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_globals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:39 by rcatini           #+#    #+#             */
/*   Updated: 2023/03/15 10:02:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

char	*parse_ambient(t_parsed_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC, COLOR};
	void				*params[sizeof(syntax) / sizeof(*syntax)];

	if (scene->ambient.initialized)
		return (free_tokens(--tokens), "Ambient already initialized");
	params[0] = &scene->ambient.intensity;
	params[1] = &scene->ambient.color;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), "Invalid ambient syntax");
	scene->ambient.initialized = 1;
	return (free_tokens(--tokens), NULL);
}

char	*parse_camera(t_parsed_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC_3, DEC};
	void				*params[sizeof(syntax) / sizeof(*syntax)];

	if (scene->camera.initialized)
		return (free_tokens(--tokens), "Camera already initialized");
	params[0] = &scene->camera.position;
	params[1] = &scene->camera.direction;
	params[2] = &scene->camera.fov_degrees;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), "Invalid camera syntax");
	scene->camera.initialized = 1;
	return (free_tokens(--tokens), NULL);
}

char	*parse_light(t_parsed_scene *scene, char **tokens)
{
	const t_parameter	syntax[] = {DEC_3, DEC, COLOR};
	void				*params[sizeof(syntax) / sizeof(*syntax)];

	if (scene->light.initialized)
		return (free_tokens(--tokens), "Light already initialized");
	params[0] = &scene->light.position;
	params[1] = &scene->light.intensity;
	params[2] = &scene->light.color;
	if (parse_items(sizeof(syntax) / sizeof(*syntax), tokens, syntax, params))
		return (free_tokens(--tokens), "Invalid light syntax");
	scene->light.initialized = 1;
	return (free_tokens(--tokens), NULL);
}
