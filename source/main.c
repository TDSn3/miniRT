/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/01 13:29:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int			red_button(t_mwi *mwi);
int			gen_new_img(t_all_data *all_data);
static void	test(t_all_data *all_data);

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

		test(all_data);

// //	*********************************************************************************

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

static void	test(t_all_data *all_data)
{
	t_world		w;
	t_camera	c;
	t_light		light;
	t_object	*sp1;
	t_object	*pl1;
	t_object	*cy1;
	t_dp		data_parsing;

/* ************************************************************************** */
/*   Lumière ambiante   A   0.2   255,255,255                                 */
/* ************************************************************************** */
	data_parsing.ambient = 0.2;

	data_parsing.a_color.x = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.y = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.z = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.w = 0;

/* ************************************************************************** */
/*   Camera   C   0,0,20.6   0,0,1   70		                                  */
/* ************************************************************************** */
	data_parsing.c_position.x = 0;
	data_parsing.c_position.y = 10;
	data_parsing.c_position.z = -50;

	data_parsing.c_to.x = 0;
	data_parsing.c_to.y = 0;
	data_parsing.c_to.z = 1;

	data_parsing.c_fov = 70;


	c = give_camera(150, 100, data_parsing.c_fov);
	c.transform = view_transform(
			(t_tuple){{data_parsing.c_position.x, data_parsing.c_position.y, data_parsing.c_position.z, 1}},
			(t_tuple){{data_parsing.c_to.x, data_parsing.c_to.y, data_parsing.c_to.z, 1}},
			(t_tuple){{0, 1, 0, 0}});

/* ************************************************************************** */
/*   Lumière   L   0,0,20.6   0.6   10,0,255	  	                          */
/* ************************************************************************** */
	data_parsing.l_position.x = 0;
	data_parsing.l_position.y = 20;
	data_parsing.l_position.z = -50;

	data_parsing.l_i = 1;

	data_parsing.l_color.x = conv_color(10);
	data_parsing.l_color.y = conv_color(0);
	data_parsing.l_color.z = conv_color(255);


	light.position = (t_tuple){{data_parsing.l_position.x, data_parsing.l_position.y, data_parsing.l_position.z, 1}};
	light.intensity = (t_tuple){{data_parsing.l_i, data_parsing.l_i, data_parsing.l_i, 0}};
	w.light = light;

/* ************************************************************************** */
/*   Sphère   sp   0,0,20.6   12.6   10,0,255		                          */
/* ************************************************************************** */
	float		rayon_sp1;

	sp1 = so_new(SPHERE, data_parsing);
	rayon_sp1 = 10;
	sp1->transform = multiply_matrix4(
			translation((t_tuple){{0, 0, 20, 0}}),
			scaling((t_tuple){{rayon_sp1, rayon_sp1, rayon_sp1, 0}}));
	sp1->material.color = (t_tuple){{conv_color(10), conv_color(0), conv_color(255), 0}};

/* ************************************************************************** */
/*   Plan   pl   0,0,0   0,0,1   0,0,255		                              */
/* ************************************************************************** */
	pl1 = so_new(PLANE, data_parsing);

//	pl1->transform = multiply_matrix4(pl1->transform, rotation_x(0 * 180));
//	pl1->transform = multiply_matrix4(pl1->transform, rotation_y(0 * 180));
//	pl1->transform = multiply_matrix4(pl1->transform, rotation_z(1 * 180));
	pl1->transform = multiply_matrix4(pl1->transform, translation((t_tuple){{0, -20, 0, 0}}));

	pl1->material.color = (t_tuple){{conv_color(150), conv_color(10), conv_color(10), 0}};

/* ************************************************************************** */
/*   Cylindre   cy   50,0,6   0,0,1   14.2   21.42   10,0,255		          */
/* ************************************************************************** */
	cy1 = so_new(CYLINDER, data_parsing);

	cy1->transform = multiply_matrix4(cy1->transform, rotation_x(40));
//	cy1->transform = multiply_matrix4(cy1->transform, rotation_y(5));
//	cy1->transform = multiply_matrix4(cy1->transform, rotation_z(10));
//	cy1->transform = multiply_matrix4(cy1->transform, scaling((t_tuple){{1.2, 1.2, 1.2, 0}}));
	cy1->transform = multiply_matrix4(cy1->transform, translation((t_tuple){{10, 0, 30, 0}}));

	cy1->cyl_max = 20;
	cy1->cyl_min = -20;
	cy1->cyl_closed = 1;
	cy1->material.color = (t_tuple){{conv_color(10), conv_color(255), conv_color(0), 0}};

/* ************************************************************************** */
	so_add_back(&sp1, pl1);
	so_add_back(&sp1, cy1);
	w.lst_object = sp1;
	render(all_data, c, &w);
	so_clear(&sp1);
	printf("end\n");
}
