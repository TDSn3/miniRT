/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 23:58:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_mwi *mwi);
int	gen_new_img(t_all_data *all_data);

int	main(void)
{
	t_mwi			mwi;
	t_data_mlx_img	data_img;
	t_all_data		all_data;

	mwi.mlx = NULL;
	mwi.win = NULL;
	mwi.data_img = &data_img;
	mwi.data_img->img = NULL;
	mwi.win_widht = 100;
	mwi.win_height = 100;
	all_data.mwi = &mwi;
	all_data.data_img = &data_img;

	mwi.mlx = mlx_init();
	mwi.win = mlx_new_window(mwi.mlx, mwi.win_widht, mwi.win_height, "miniRT");
	mlx_hook(mwi.win, 17, 0L, red_button, &mwi);
	mlx_loop_hook(mwi.mlx, gen_new_img, &all_data);
	mlx_loop(mwi.mlx);
	return (0);
}

int	red_button(t_mwi *mwi)
{
	if (mwi->data_img->img)
		mlx_destroy_image(mwi->mlx, mwi->data_img->img);
	mlx_destroy_window(mwi->mlx, mwi->win);
//	mlx_destroy_display(mwi->mlx);
	free(mwi->mlx);
	exit (0);
	return (0);
}

int	gen_new_img(t_all_data *all_data)
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;

	data_img = all_data->data_img;
	mwi = all_data->mwi;
	data_img -> img = mlx_new_image(mwi -> mlx, 1080, 720);
	data_img -> addr = mlx_get_data_addr(
			mwi -> data_img -> img,
			&mwi -> data_img -> bits_per_pixel,
			&mwi -> data_img -> line_length,
			&mwi -> data_img -> endian);
//	pixel_put ***********************************************************************

	t_material	m;
	t_tuple		position = (t_tuple){0, 0, 0, 0};
	t_tuple		eyev = (t_tuple){0, 0, -1, 0};
	t_tuple		normalv = (t_tuple){0, 0, -1, 0};
	t_light		light;
	t_tuple		result;

	m.color = (t_tuple){1, 1, 1, 0};
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200;

	light.position = (t_tuple){0, 0, -10, 1};
	light.intensity = (t_tuple){1, 1, 1, 0};
	result = lighting(m, light, position, eyev, normalv);

	printf("%f %f %f \n", result.x, result.y, result.z);

	print_canvas(all_data);

//	*********************************************************************************

//	for (int i = -10 ; i < 10; i++)
//	{
//		my_mlx_pixel_put(all_data, 0, i, 0x00FF0000);
//		my_mlx_pixel_put(all_data, i, 0, 0x00FF0000);
//	}	

//	*********************************************************************************
	mlx_put_image_to_window(
		mwi -> mlx,
		mwi -> win,
		mwi -> data_img -> img,
		0,
		0);
	mlx_destroy_image(mwi -> mlx, mwi -> data_img -> img);
	mwi -> data_img -> img = NULL;
	return (0);
}
