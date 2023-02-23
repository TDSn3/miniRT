/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/23 00:19:14 by tda-silv         ###   ########.fr       */
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

//	t_matrix4 mtx = {.tab = {{8, -5, 9, 2}, {7, 5, 6, 1}, {-6, 0, 9, 6}, {-3, 0, -9, -4}}};
//	t_matrix4 mtx2;
//
//	printf("%f\n", determinant_matrix4(mtx));
//	inverse_matrix4(mtx, &mtx2);
//	printf("%f\n", mtx.tab[3][3]);
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
