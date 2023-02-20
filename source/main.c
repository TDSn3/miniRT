/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 22:51:57 by tda-silv         ###   ########.fr       */
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

	t_intersection	*a;
	t_to			stock;

	a = NULL;
	si_add_back(&a, si_new((t_3f){2, 5, 7}, (t_object){1, (t_tuple){0, 0, 0}}));
	si_add_back(&a, si_new((t_3f){2, -3, 2}, (t_object){1, (t_tuple){0, 0, 0}}));
	stock = hit(a);
	printf("->%f \n", stock.t);
	if (stock.t == FLT_MAX)
		printf("ERROR \n", stock.t);

//	intersect((t_tuple){0, 0, 1}, (t_tuple){0, 0, 5}, (t_object){1, (t_tuple){0, 0, 0}});
	si_clear(&a);
	red_button(mwi);
//	t_tuple	point;
//	t_tuple	point2;
//	t_tuple	point3;
//	t_tuple	point4;
//
//	init_point(&point, 1, 0, 1);
//	init_point(&point2, 0, 0, 0);
//	init_point(&point3, 0, 0, 0);
//	init_point(&point4, 0, 0, 0);
//
//	transform(&point2, rotation_x(90), &point);
//	transform(&point3, scaling((t_tuple){5, 5, 5, 0}), &point2);
//	transform(&point4, translation((t_tuple){10, 5, 7, 0}), &point3);
//	printf("%f %f %f\n", point4.x, point4.y, point4.z);

//	t_tuple	test;
//	test.x = 33;
//	printf("----------->%f\n", test.tuple[0]);

//	*********************************************************************************

	for (int i = -10 ; i < 10; i++)
	{
		my_mlx_pixel_put(all_data, 0, i, 0x00FF0000);
		my_mlx_pixel_put(all_data, i, 0, 0x00FF0000);
	}	

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
