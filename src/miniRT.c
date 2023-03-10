/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:25:32 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parser.h"

void	mlx_loop_and_exit(t_mlx_data *mlx_data)
{
	mlx_loop(mlx_data->mlx);
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
}

int	get_parsed_scene(char *filename, t_parsed_scene *scene)
{
	*scene = (t_parsed_scene){0};
	if (parse_scene(filename, scene))
		return (free_objects(scene->objects), 2);
	print_objects(scene);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_data		all_data;
	t_parsed_scene	parsed_scene;

	if (argc != 2)
		return (printf("Usage: ./miniRT <scene_file.rt>\n"), 1);
	if (get_parsed_scene(argv[1], &parsed_scene))
		return (1);
	if (init_all_data(&all_data, &parsed_scene))
		return (1);
	mlx_hook(all_data.mlx_data.win, 17, 0L, red_button, &all_data);
	mlx_key_hook(all_data.mlx_data.win, key_press_hook, &all_data);
	render(&all_data.mlx_data, &all_data.camera, all_data.objects,
		&all_data.light);
	mlx_loop_and_exit(&all_data.mlx_data);
	object_lst_clear(&all_data.objects);
}
