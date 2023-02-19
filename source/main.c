/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 23:46:30 by tda-silv         ###   ########.fr       */
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

	t_matrix	matrix1;
	t_tuple		vect;
	t_tuple		point;
	t_tuple		point2;

	init_vector(&vect, 2, 3, 4);
	init_point(&point, -4, 6, 8);
	init_point(&point2, 0, 0, 0);

	init_matrix(&matrix1, 4, 4);

	transform(&point2, scaling(&vect), &point);

	printf("%f ", point2.x);
	printf("%f ", point2.y);
	printf("%f \n", point2.z);

	matrix1.tab[0][0] = 9; matrix1.tab[0][1] = 3; matrix1.tab[0][2] = 0; matrix1.tab[0][3] = 9;
	matrix1.tab[1][0] = -5; matrix1.tab[1][1] = -2; matrix1.tab[1][2] = -6; matrix1.tab[1][3] = -3;
	matrix1.tab[2][0] = -4; matrix1.tab[2][1] = 9; matrix1.tab[2][2] = 6; matrix1.tab[2][3] = 4;
	matrix1.tab[3][0] = -7; matrix1.tab[3][1] = 6; matrix1.tab[3][2] = 6; matrix1.tab[3][3] = 2;

//	matrix2 = translation();
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			printf("%f ", matrix2->tab[i][j]);
//		printf("\n");
//	}
	printf("\n\n");

	free_matrix(&matrix1);
//	free_matrix(matrix2);

//	t_tuple	test;
//	test.x = 33;
//	printf("----------->%f\n", test.tuple[0]);

//	*********************************************************************************

	for (int i = -10 ; i < 10; i++)
	{
		my_mlx_pixel_put(all_data, 0, i, 0x00FF0000);
		my_mlx_pixel_put(all_data, i, 0, 0x00FF0000);
	}	

	t_tuple	start;
	t_tuple	velocity;
//	t_tuple	p;
	t_tuple	gravity;
	t_tuple	wind;
//	t_tuple	e;
//	t_tuple	c;

	init_point(&start, 0, 1, 0);
	init_vector(&velocity, 1, 1.8, 0);
	normalization_vector(&velocity);
	t_tuple_multi_scal(&velocity, &velocity, 8);
	init_vector(&gravity, 0, -0.1, 0);
	init_vector(&wind, -0.01, 0, 0);

	for (int i = 0 ; i < 200; i++)
	{
		t_tuple_plus(&start, &start, &velocity);
		t_tuple_plus(&velocity, &velocity, &gravity);
		t_tuple_plus(&velocity, &velocity, &wind);
		my_mlx_pixel_put(all_data, start.x, start.y, 0x00ffffff);
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
