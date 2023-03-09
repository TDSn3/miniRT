/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 02:20:50 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

void	print_scene(t_parsed_scene const *scene)
{
	t_parsed_object	*objects;

	printf("ambient: %f %d,%d,%d\n", scene->ambient.intensity, scene->ambient.color.r, scene->ambient.color.g, scene->ambient.color.b);
	printf("camera: %f,%f,%f, %f,%f,%f %f\n", scene->camera.position.x, scene->camera.position.y, scene->camera.position.z, scene->camera.direction.x, scene->camera.direction.y, scene->camera.direction.z, scene->camera.fov_degrees);
	printf("light: %f,%f,%f %f %d, %d, %d\n", scene->light.position.x, scene->light.position.y, scene->light.position.z, scene->light.intensity, scene->light.color.r, scene->light.color.g, scene->light.color.b);
	printf("objects:\n");
	objects = scene->objects;
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
	t_parsed_scene	scene;

	scene = (t_parsed_scene){0};
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	return (printf("Usage: ./miniRT <scene_file.rt>\n"), 1);
	// scene = (t_parsed_scene){0};
	// if (parse_scene(argv[1], &scene))
	// 	return (free_objects(scene.objects), 2);
	if (init_all(&all_data.mlx_data, &all_data.data_key, &all_data.scene, &scene))
		return (printf("Error\nFailed to initialize world\n"), 1);
	free_objects(scene.objects);
	gen_new_img(&all_data.mlx_data, &all_data.scene);
	mlx_hook(all_data.mlx_data.win, 17, 0L, red_button, &all_data);
	// mlx_hook(all_data.mlx_data.win, 2, 1L << 0L, key_press_hook, &all_data);
	// mlx_hook(all_data.mlx_data.win, 3, 1L << 1L, key_release_hook, &all_data);
	mlx_mouse_hook(all_data.mlx_data.win, mouse_hook, &all_data);
	mlx_loop(all_data.mlx_data.mlx);
	if (all_data.mlx_data.img)
		mlx_destroy_image(all_data.mlx_data.mlx, all_data.mlx_data.img);
	mlx_destroy_window(all_data.mlx_data.mlx, all_data.mlx_data.win);
	mlx_destroy_display(all_data.mlx_data.mlx);
	object_lst_clear(&all_data.scene.objects);
	free(all_data.mlx_data.mlx);
}
