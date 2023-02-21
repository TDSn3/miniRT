/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 18:37:33 by tda-silv         ###   ########.fr       */
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
	mwi.win_widht = 1080;
	mwi.win_height = 720;
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

//	t_tuple	ray_origin = {0, 0, -5, 1};
//	float	wall_z = 10;
//	float	wall_size = 10;
//	float	canvas_pixels = 300;
//	float	pixel_size = wall_size / canvas_pixels;
//	float	half = wall_size / 2;
//	float	world_y;
//	float	world_x;
//	t_tuple	position;
//	t_ray	r;
//	t_tuple stock;
//	t_intersection	inter;
//	t_object		shape = {1, (t_tuple){0,0,0,1}, shearing((t_6f){1,0,0,0,0,0})};
//
//	r.point = ray_origin;
//	for (float y = 0; y < canvas_pixels; y++)
//	{
//		world_y = half - pixel_size * y;
//		for (float x = 0; x < canvas_pixels; x++)
//		{
//			world_x = -half + pixel_size * x;
//			init_point(&position, world_x, world_y, wall_z);
//			stock = t_tuple_minus(position, ray_origin);
//			normalization_vector(&stock);
//			r.vector = stock;
//			inter = intersect(r.vector, r.point, shape);
//			if (hit(&inter).t)
//				my_mlx_pixel_put(all_data, x, y, 0x00FF0000);
//		}
//	}
//	free(shape.transform);

	t_tuple	ray_origin = {0, 0, -5, 1};
	float	wall_z = 10;
	float	wall_size = 10;
	float	canvas_pixels = 300;
	float	pixel_size = wall_size / canvas_pixels;
	float	half = wall_size / 2;
	float	world_y;
	float	world_x;

	t_tuple	stock_position;
	t_tuple	point;
	t_ray	r;
	t_to	stock_hit;
	t_tuple stock;
	t_intersection	inter;
	t_object		shape = {1, (t_tuple){0,0,0,1}, shearing((t_6f){1,0,0,0,0,0})}; //
	t_material		mat;
	t_light			light;
	t_tuple			stock_normal;

	light.intensity = (t_tuple){1,1,1,0};
	light.position = (t_tuple){-10,10,-10,1};
	mat.color = (t_tuple){1, 0.2, 1, 0};
	shape.material = mat;

	r.point = ray_origin;
	for (float y = 0; y < canvas_pixels; y++)
	{
		world_y = half - pixel_size * y;
		for (float x = 0; x < canvas_pixels; x++)
		{
			world_x = -half + pixel_size * x;
			init_point(&stock_position, world_x, world_y, wall_z);
			stock = t_tuple_minus(stock_position, ray_origin);
			normalization_vector(&stock);
			r.vector = stock;
			inter = intersect(r.vector, r.point, shape);
			stock_hit = hit(&inter);
			if (stock_hit.t)
				my_mlx_pixel_put(all_data, x, y, 0x00FF0000);
			point = position(r.vector, r.point, stock_hit.t);
			stock_normal = normal_at(stock_hit.object, point);
		}
	}
	free(shape.transform);

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
