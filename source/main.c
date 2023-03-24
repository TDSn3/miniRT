/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 19:07:50 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	start_parsing(
				int argc,
				char **argv,
				t_all_data *all_data,
				t_parsed_scene *parsed_scene);
static int	get_parsed_scene(char *filename, t_parsed_scene *scene);

void	destruct_everything(t_all_data *all_data, t_parsed_scene *parsed_scene)
{
	mlx_destroy_image(all_data->mwi->mlx, all_data->mwi->img);
	mlx_destroy_window(all_data->mwi->mlx, all_data->mwi->win);
	mlx_destroy_display(all_data->mwi->mlx);
	free(all_data->mwi->mlx);
	free_objects(parsed_scene->objects);
	so_clear(&all_data->list_object);
}

int	main(int argc, char **argv)
{
	t_all_data		all_data;
	t_mwi			mwi;
	t_dk			data_key;
	t_parsed_scene	parsed_scene;

	if (start_parsing(argc, argv, &all_data, &parsed_scene))
		return (1);
	if (init_all(&all_data, &mwi, &data_key))
		return (free_objects(parsed_scene.objects),
			printf("Error\nerror initializing mlx"), 1);
	mlx_hook(mwi.win, 17, 0L, red_button, &all_data);
	mlx_hook(mwi.win, 2, 1L << 0L, key_press_hook, &all_data);
	mlx_hook(mwi.win, 3, 1L << 1L, key_release_hook, &all_data);
	mlx_mouse_hook(mwi.win, mouse_hook, &all_data);
	gen_new_img(&all_data);
	mlx_loop(mwi.mlx);
	destruct_everything(&all_data, &parsed_scene);
	return (0);
}

static int	start_parsing(
	int argc, char **argv, t_all_data *all_data, t_parsed_scene *parsed_scene)
{
	if (argc != 2)
		return (printf("Usage: ./miniRT <scene_file.rt>\n"), 1);
	if (get_parsed_scene(argv[1], parsed_scene))
		return (1);
	all_data->parsed_scene = parsed_scene;
	return (0);
}

static int	get_parsed_scene(char *filename, t_parsed_scene *scene)
{
	*scene = (t_parsed_scene){0};
	if (parse_scene(filename, scene))
		return (free_objects(scene->objects), 2);
	return (0);
}
