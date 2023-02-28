/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_globals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:39 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 10:02:11 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*parse_ambient(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL, BYTE_3};

	(void)scene;
	(void)line;
	// if (scene->ambient.initialized)
	// 	return (printf("Error: Ambient already initialized\n"), 1);
	// if (sscanf(line, "A %lf %hhu,%hhu,%hhu", &scene->ambient.intensity,
	// 		&scene->ambient.color.r, &scene->ambient.color.g,
	// 		&scene->ambient.color.b) != 4)
	// 	return (printf("Error: Invalid ambient\n"), 1);
	// perror("ambient");
	// scene->ambient.initialized = 1;
	return (NULL);
}

char	*parse_camera(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL_3, DECIMAL_3, INTEGER};

	(void)scene;
	(void)line;
	// if (scene->camera.initialized)
	// 	return (printf("Error: Camera already initialized\n"), 1);
	// if (sscanf(line, "C %lf,%lf,%lf %lf,%lf,%lf %lf",
	// &scene->camera.position.x,
	// 		&scene->camera.position.y, &scene->camera.position.z,
	// 		&scene->camera.direction.x, &scene->camera.direction.y,
	// 		&scene->camera.direction.z, &scene->camera.fov) != 7)
	// 	return (printf("Error: Invalid camera\n"), 1);
	// perror("camera");
	// scene->camera.initialized = 1;
	return (NULL);
}

char	*parse_light(t_world *scene, char *line)
{
	const t_parameter	syntax[] = {DECIMAL_3, DECIMAL, BYTE_3};

	(void)scene;
	(void)line;
	// if (scene->light.initialized)
	// 	return (printf("Error: Light already initialized\n"), 1);
	// if (sscanf(line, "L %lf,%lf,%lf %lf %hhu,%hhu,%hhu",
	// 		&scene->light.position.x, &scene->light.position.y,
	// 		&scene->light.position.z, &scene->light.intensity,
	// 		&scene->light.color.r, &scene->light.color.g,
	// 		&scene->light.color.b) != 7)
	// 	return (printf("Error: Invalid light\n"), 1);
	// perror("light");
	// scene->light.initialized = 1;
	return (NULL);
}
