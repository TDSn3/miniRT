/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 13:35:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_mwi *mwi);
int	gen_new_img(t_all_data *all_data);

int	i_img;

int	main(void)
{
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
		s2->material.color = (t_tuple){{1, 0.2, 1, 0}};

		so_add_back(&s1, s2);

		w.light = light;
		w.lst_object = s1;

		r.vector = (t_tuple){{0, 0, 1, 0}};
		r.point = (t_tuple){{0, 0, -5, 1}};

		t = intersection(4, s1);
		comps = prepare_computations(r, &t);
		printf("%f %f %f\n", comps.point.x, comps.point.y, comps.point.z);
		printf("%f %f %f\n", comps.eyev_vector.x, comps.eyev_vector.y, comps.eyev_vector.z);
		printf("%f %f %f\n", comps.normalv_vector.x, comps.normalv_vector.y, comps.normalv_vector.z);

		so_clear(&s1);

		print_canvas(all_data);

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
