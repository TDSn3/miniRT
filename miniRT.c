/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/06 06:12:41 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

int	main(int argc, char **argv)
{
	// t_all_data		all_data;
	// t_mwi			mwi;
	// t_data_mlx_img	data_img;
	// t_dk			data_key;
	t_scene			scene;

	scene = (t_scene){0};
	if (argc != 2)
		return (printf("Usage: ./miniRT <scene_file.rt>\n"), 1);
	if (parse_scene(argv[1], &scene))
		return (2);
	printf("Scene parsed successfully!\n");
	printf("ambient: %f %d,%d,%d\n", scene.ambient.intensity, scene.ambient.color.r, scene.ambient.color.g, scene.ambient.color.b);
	printf("camera: %f,%f,%f, %f,%f,%f %f\n", scene.camera.position.a, scene.camera.position.b, scene.camera.position.c, scene.camera.direction.a, scene.camera.direction.b, scene.camera.direction.c, scene.camera.fov_degrees);
	printf("light: %f,%f,%f %f %d, %d, %d\n", scene.light.position.a, scene.light.position.b, scene.light.position.c, scene.light.intensity, scene.light.color.r, scene.light.color.g, scene.light.color.b);
	// init_all(&all_data, &mwi, &data_img, &data_key);
	// mlx_hook(mwi.win, 17, 0L, red_button, &all_data);
	// mlx_hook(mwi.win, 2, 1L << 0L, key_press_hook, &all_data);
	// mlx_hook(mwi.win, 3, 1L << 1L, key_release_hook, &all_data);
	// mlx_mouse_hook(mwi.win, mouse_hook, &all_data);
	// mlx_loop_hook(mwi.mlx, gen_new_img, &all_data);
	// mlx_loop(mwi.mlx);
}
