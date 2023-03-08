/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 03:15:49 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

void	print_objects(t_parsed_object *objects)
{
	printf("Printing objects:\n");
	while (objects)
	{
		if (objects->type == SPHERE)
			printf("\tsphere: %f,%f,%f %f %d,%d,%d\n", objects->position.x, objects->position.y, objects->position.z, objects->radius, objects->color.r, objects->color.g, objects->color.b);
		else if (objects->type == PLANE)
			printf("\tplane: %f,%f,%f %f,%f,%f %d,%d,%d\n", objects->position.x, objects->position.y, objects->position.z, objects->direction.x, objects->direction.y, objects->direction.z, objects->color.r, objects->color.g, objects->color.b);
		else if (objects->type == CYLINDER)
			printf("\tcylinder: %f,%f,%f %f,%f,%f %f %f %d,%d,%d\n", objects->position.x, objects->position.y, objects->position.z, objects->direction.x, objects->direction.y, objects->direction.z, objects->radius, objects->height, objects->color.r, objects->color.g, objects->color.b);
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

int	main(int argc, char **argv)
{
	t_all_data		all_data;
	t_mwi			mwi;
	t_data_mlx_img	data_img;
	t_dk			data_key;
	t_scene			scene;

	scene = (t_scene){0};
	if (argc != 2)
		return (printf("Usage: ./miniRT <scene_file.rt>\n"), 1);
	if (parse_scene(argv[1], &scene))
		return (free_objects(scene.objects), 2);
	printf("Scene parsed successfully!\n");
	// printf("ambient: %f %d,%d,%d\n", scene.ambient.intensity, scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	// printf("camera: %f,%f,%f, %f,%f,%f %f\n", scene.camera.position.a, scene.camera.position.b, scene.camera.position.c, scene.camera.direction.a, scene.camera.direction.b, scene.camera.direction.c, scene.camera.fov_degrees);
	// printf("light: %f,%f,%f %f %d, %d, %d\n", scene.light.position.a, scene.light.position.b, scene.light.position.c, scene.light.intensity, scene.light.color.r, scene.light.color.g, scene.light.color.b);
	print_objects(scene.objects);
	free_objects(scene.objects);
	init_all(&all_data, &mwi, &data_img, &data_key);
	mlx_hook(mwi.win, 17, 0L, red_button, &all_data);
	mlx_hook(mwi.win, 2, 1L << 0L, key_press_hook, &all_data);
	mlx_hook(mwi.win, 3, 1L << 1L, key_release_hook, &all_data);
	mlx_mouse_hook(mwi.win, mouse_hook, &all_data);
	mlx_loop_hook(mwi.mlx, gen_new_img, &all_data);
	mlx_loop(mwi.mlx);
}
