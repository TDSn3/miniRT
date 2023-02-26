/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/26 18:59:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int			red_button(t_mwi *mwi);
int			gen_new_img(t_all_data *all_data);
static void	test(void);

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
//	mlx_destroy_display(mwi->mlx); //
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
		s2->transform = multiply_matrix4(translation((t_tuple){{1.5, 0.5, -0.5, 0}}), scaling((t_tuple){{0.5, 0.5, 0.5, 0}}));
		s2->material.color = (t_tuple){{0.5, 1, 0.1, 0}};
		s2->material.diffuse = 0.7;
		s2->material.specular = 0.3;

		s3 = so_new(3, SPHERE);
		s3->transform = multiply_matrix4(translation((t_tuple){{-1.5, 0.33, -0.75, 0}}), scaling((t_tuple){{0.33, 0.33, 0.33, 0}}));
		s3->material.color = (t_tuple){{1, 0.8, 0.1, 0}};
		s3->material.diffuse = 0.7;
		s3->material.specular = 0.3;

		so_add_back(&s1, s2);
		so_add_back(&s1, s3);
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

static void	test(void)
{
		t_world		w;
		t_light		light;
		t_object	*s1;
		t_object	*s2;
		t_ray		r;
		t_comps		comps;
		t_to		t;

		light.position = (t_tuple){{-10, 10, -10, 1}};
		light.intensity = (t_tuple){{1, 1, 1, 0}};

		s1 = so_new(1, SPHERE);
		s2 = so_new(2, SPHERE);

		s1->material.color = (t_tuple){{0.8, 1.0, 0.6, 0}};
		s1->material.ambient = 0.1;
		s1->material.diffuse = 0.7;
		s1->material.specular = 0.2;

		s2->transform = scaling((t_tuple){{0.5, 0.5, 0.5, 0}});
//		s2->material.color = (t_tuple){{1, 0.2, 1, 0}};

		so_add_back(&s1, s2);

		w.light = light;
		w.lst_object = s1;

		r.vector = (t_tuple){{0, 0, 1, 0}};
		r.point = (t_tuple){{0, 0, -5, 1}};

		t = intersection(1, s1);
		comps = prepare_computations(r, &t);
		printf("%f %f %f\n", comps.point.x, comps.point.y, comps.point.z);
		printf("%f %f %f\n", comps.eyev_vector.x, comps.eyev_vector.y, comps.eyev_vector.z);
		printf("%f %f %f\n", comps.normalv_vector.x, comps.normalv_vector.y, comps.normalv_vector.z);
		printf("%d\n", comps.inside);

		t_tuple	stock_co = color_at(&w, r);
		printf("%f %f %f\n", stock_co.x, stock_co.y, stock_co.z);
		printf("---------\n");

		t_matrix4 stock = view_transform((t_tuple){{0, 0, 0, 0}}, (t_tuple){{0, 0, -1, 0}}, (t_tuple){{0, 1, 0, 0}});
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%f ", stock.tab[i][j]);
			}
			printf("\n");
		}

		printf("++++++++++\n");
		t_camera	c = give_camera(201, 101, M_PI / 2);
		c.transform = multiply_matrix4(rotation_y(M_PI / 4), translation((t_tuple){{0, -2, 5, 0}}));
		t_ray		rr = ray_for_pixel(c, 100, 50);
		printf("%f %f %f %f \n", rr.point.x, rr.point.y, rr.point.z, rr.point.w);
		printf("%f %f %f %f \n", rr.vector.x, rr.vector.y, rr.vector.z, rr.vector.w);
		
		so_clear(&s1);
}
