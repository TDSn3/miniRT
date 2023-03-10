/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 06:44:43 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <header.h>

int	init_mlx_data(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (1);
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "miniRT");
	if (!mlx_data->win)
		return (free(mlx_data->mlx), 1);
	mlx_data->img = mlx_new_image(mlx_data->mlx,
			WIDTH, HEIGHT);
	if (!mlx_data->img)
		return (free(mlx_data->mlx), free(mlx_data->win), 1);
	mlx_data->addr = (unsigned int *)mlx_get_data_addr(
			mlx_data->img, &mlx_data->bits_per_pixel,
			&mlx_data->line_length, &mlx_data->endian);
	if (!mlx_data->addr)
		return (free(mlx_data->mlx), free(mlx_data->win),
			free(mlx_data->img), 1);
	return (0);
}

int	init_all_data(t_all_data *all_data, t_parsed_scene *scene)
{
	*all_data = (t_all_data){0};
	if (init_mlx_data(&all_data->mlx_data))
		return (printf("Error\nFailed to initialize mlx\n"), 1);
	if (init_camera(&all_data->camera, &scene->camera))
		return (printf("Error\nFailed to initialize camera\n"), 1);
	if (init_light(&all_data->light, &scene->light))
		return (printf("Error\nFailed to initialize light\n"), 1);
	if (!scene->objects)
		return (printf("Error\nNo objects in scene\n"), 1);
	all_data->objects = init_objects(scene->objects, &scene->ambient);
	if (!all_data->objects)
		return (printf("Error\nFailed to initialize objects\n"), 1);
	return (0);
}
