/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 02:13:30 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <header.h>

int	init_mlx(t_mlx_data *mlx_data)
{
	*mlx_data = (t_mlx_data){0};

	mlx_data->mlx = mlx_init();
	if (mlx_data->mlx == NULL)
		return (1);
	mlx_data->win = mlx_new_window(mlx_data->mlx,
			WIDTH, HEIGHT, "miniRT");
	if (mlx_data->win == NULL)
		return (mlx_destroy_display(mlx_data->mlx), 1);
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	if (mlx_data->img == NULL)
		return (mlx_destroy_window(mlx_data->mlx, mlx_data->win),
			mlx_destroy_display(mlx_data->mlx), 1);
	mlx_data->addr = (unsigned int *)mlx_get_data_addr(mlx_data->img,
			&mlx_data->bits_per_pixel, &mlx_data->line_length,
			&mlx_data->endian);
	return (0);
}

int	init_scene(t_scene *scene, t_parsed_scene const *parsed_scene)
{
	(void)parsed_scene;
	*scene = (t_scene){0};
	scene->camera = give_camera(WIDTH, HEIGHT, 70);
	view_transform((t_tuple){{0, -50, -20, 1}}, (t_tuple){{0, 1, 0, 0}},
		(t_tuple){{0, 1, 0, 0}}, &scene->camera.transform);
	inverse_matrix4(&scene->camera.transform, &scene->camera.inverse);
	scene->objects = object_lst_new(SPHERE, &scene->ambient);
	translation((t_tuple){{0, 0, -30, 0}}, &scene->objects->transform);
	inverse_matrix4(&scene->objects->transform, &scene->objects->inverse);
	return (0);
}

int	init_all(t_mlx_data *mlx_data, t_dk *data_key, t_scene *scene,
		t_parsed_scene const *parsed_scene)
{
	*data_key = (t_dk){0};
	if (init_mlx(mlx_data))
		return (1);
	if (init_scene(scene, parsed_scene))
		return (1);
	return (0);
}
