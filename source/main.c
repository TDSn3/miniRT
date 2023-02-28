/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 21:40:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int			red_button(t_mwi *mwi);
int			gen_new_img(t_all_data *all_data);
//static void	test(void);

int	i_img;

int	main(void)
{
//	test();
	t_mwi			mwi;
	t_data_mlx_img	data_img;
	t_all_data		all_data;

	i_img = 0;
	mwi.mlx = NULL;
	mwi.win = NULL;
	mwi.data_img = &data_img;
	mwi.data_img->img = NULL;
	mwi.win_widht = 500;
	mwi.win_height = 500;
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
//	mlx_destroy_display(mwi->mlx); // <------- Ok sur Linux mais pas sur MacOs
	free(mwi->mlx);
	exit (0);
	return (0);
}

int	gen_new_img(t_all_data *all_data)
{
	t_mwi			*mwi;
	t_data_mlx_img	*data_img;

	if (i_img == 0)
	{
		printf("%sNew image%s\n", COLOR_BOLD_YELLOW, COLOR_RESET);
		data_img = all_data->data_img;
		mwi = all_data->mwi;
		data_img -> img = mlx_new_image(mwi -> mlx, 1080, 720);
		data_img -> addr = mlx_get_data_addr(
				mwi -> data_img -> img,
				&mwi -> data_img -> bits_per_pixel,
				&mwi -> data_img -> line_length,
				&mwi -> data_img -> endian);

//	pixel_put ***********************************************************************

		t_camera	c;
		t_world		w;
		t_light		light;
		t_object	*s1;
		t_object	*s2;
		t_object	*s3;
		t_object	*s4;
		t_object	*s5;
		t_object	*s6;

		c = give_camera(300, 110, M_PI / 3);
		c.transform = view_transform(
				(t_tuple){{0, 1.5, -5, 1}},
				(t_tuple){{0, 1, 0, 1}},
				(t_tuple){{0, 1, 0, 0}});
		c.hsize = 400;
		c.vsize = 400;

		light.position = (t_tuple){{-10, -10, -10, 1}};
		light.intensity = (t_tuple){{1, 1, 1, 0}};
		w.light = light;

		s1 = so_new(1, SPHERE);
		s1->transform = translation((t_tuple){{-0.5, 1, 0.5, 0}});
		s1->material.color = (t_tuple){{0.1, 1, 0.5, 0}};
		s1->material.diffuse = 0.7;
		s1->material.specular = 0.3;

		s2 = so_new(2, SPHERE);
		s2->transform = multiply_matrix4(translation((t_tuple){{1.5, 0.5, 9, 0}}), scaling((t_tuple){{0.5, 0.5, 0.5, 0}}));
		s2->material.color = (t_tuple){{0.5, 1, 0.1, 0}};
		s2->material.diffuse = 0.7;
		s2->material.specular = 0.3;

		s3 = so_new(3, SPHERE);
		s3->transform = multiply_matrix4(translation((t_tuple){{-1.5, 0.33, -0.75, 0}}), scaling((t_tuple){{0.33, 0.33, 0.33, 0}}));
		s3->material.color = (t_tuple){{1, 0.8, 0.1, 0}};
		s3->material.diffuse = 0.7;
		s3->material.specular = 0.3;

		s4 = so_new(4, PLANE);
		s4->transform = translation((t_tuple){{0, 0.2, 0, 0}});
		s4->material.color = (t_tuple){{0.6, 0.6, 0.6, 0}};
		s4->material.diffuse = 0.7;
		s4->material.specular = 0.3;

		s5 = so_new(5, PLANE);
		s5->transform = multiply_matrix4(rotation_x(90), translation((t_tuple){{0, 10, 0, 0}}));
		s5->material.color = (t_tuple){{0.5, 0.5, 0.5, 0}};
		s5->material.diffuse = 0.7;
		s5->material.specular = 0.3;

		s6 = so_new(6, CYLINDER);
		s6->transform = multiply_matrix4(translation((t_tuple){{0, -4, 4, 0}}), multiply_matrix4(rotation_x(-50), rotation_z(20)));
		s6->material.color = (t_tuple){{0.8, 0.2, 0.7, 0}};
		s6->material.diffuse = 0.7;
		s6->material.specular = 0.3;
		s6->cyl_max = 2;
		s6->cyl_min = -2;
		s6->cyl_closed = 1;

		so_add_back(&s1, s2);
		so_add_back(&s1, s3);
		so_add_back(&s1, s4);
		so_add_back(&s1, s5);
		so_add_back(&s1, s6);
		w.lst_object = s1;

		render(all_data, c, &w);
		so_clear(&s1);

//	*********************************************************************************

		mlx_put_image_to_window(
			mwi -> mlx,
			mwi -> win,
			mwi -> data_img -> img,
			0,
			0);
		mlx_destroy_image(mwi -> mlx, mwi -> data_img -> img);
		mwi -> data_img -> img = NULL;
		i_img++;
	}
	return (0);
}

/*
static void	test(void)
{
	t_object		*s1;
	t_tuple			direction =  normalization_vector((t_tuple){{0, -1, 0, 0}});
	t_tuple			origin = (t_tuple){{0, 3, 0, 1}};
	t_intersection	stock;

	s1 = so_new(1, CYLINDER);
	s1->cyl_min = 1;
	s1->cyl_max = 2;
	s1->cyl_closed = 1;
	stock = intersect(direction, origin, s1);
	printf("%f %f %f\n", stock.t.a, stock.t.b, stock.t.c);
//	t_tuple stock2 = normal_at(*s1, (t_tuple){{0, 1, 0, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
//	stock2 = normal_at(*s1, (t_tuple){{0.5, 1, 0, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
//	stock2 = normal_at(*s1, (t_tuple){{0, 1, 0.5, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
//	stock2 = normal_at(*s1, (t_tuple){{0, 2, 0, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
//	stock2 = normal_at(*s1, (t_tuple){{0.5, 2, 0, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
//	stock2 = normal_at(*s1, (t_tuple){{0, 2, 0.5, 1}});
//	printf("%f %f %f\n", stock2.x, stock2.y, stock2.z);
	free(s1);
}
*/