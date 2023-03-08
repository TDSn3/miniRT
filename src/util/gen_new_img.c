/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_new_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:47:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 03:33:46 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	test(t_all_data *all_data);

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
	printf("%sNew image%s\n", COLOR_BOLD_YELLOW, COLOR_RESET);
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
	t_object	*cy2;
	t_dp		data_parsing;

/* ************************************************************************** */
/*   Lumière ambiante   A   0.2   255,255,255                                 */
/* ************************************************************************** */
	data_parsing.ambient = 0.05;

	data_parsing.a_color.x = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.y = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.z = conv_color(255) * data_parsing.ambient;
	data_parsing.a_color.w = 0;

/* ************************************************************************** */
/*   Camera   C   0,0,20.6   0,0,1   70		                                  */
/* ************************************************************************** */
	data_parsing.c_position.x = 0 + all_data->data_key->c_add_pos_x;
	data_parsing.c_position.y = -50 + all_data->data_key->c_add_pos_y;
	data_parsing.c_position.z = -20 + all_data->data_key->c_add_pos_z;

	data_parsing.c_to.x = 0 + all_data->data_key->c_add_to_x;
	data_parsing.c_to.y = 1 + all_data->data_key->c_add_to_y;
	data_parsing.c_to.z = 0 + all_data->data_key->c_add_to_z;

	data_parsing.c_fov = 70 + all_data->data_key->c_add_fov;


	c = give_camera(HEIGHT, WIDHT, data_parsing.c_fov);
	c.transform = view_transform(
			(t_tuple){{data_parsing.c_position.x, data_parsing.c_position.y, data_parsing.c_position.z, 1}},
			(t_tuple){{data_parsing.c_to.x, data_parsing.c_to.y, data_parsing.c_to.z, 1}},
			(t_tuple){{0, 1, 0, 0}});

/* ************************************************************************** */
/*   Lumière   L   0,0,20.6   0.6   10,0,255	  	                          */
/* ************************************************************************** */
	data_parsing.l_position.x = 0;
	data_parsing.l_position.y = -20;
	data_parsing.l_position.z = 35;

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
	all_data->list_object = &sp1; // IMPORTANT

	rayon_sp1 = 10;
	sp1->transform = multiply_matrix4(
			translation((t_tuple){{0, 0, -30, 0}}),
			scaling((t_tuple){{rayon_sp1, rayon_sp1, rayon_sp1, 0}}));
	sp1->material.color = (t_tuple){{conv_color(10), conv_color(0), conv_color(255), 0}};

/* ************************************************************************** */
/*   Plan   pl   0,0,0   0,0,1   0,0,255		                              */
/* ************************************************************************** */
	pl1 = so_new(PLANE, data_parsing);

//	pl1->transform = multiply_matrix4(pl1->transform, rotation_x(10));
//	pl1->transform = multiply_matrix4(pl1->transform, rotation_y(10));
//	pl1->transform = multiply_matrix4(pl1->transform, rotation_z(90));
//	pl1->transform = multiply_matrix4(pl1->transform, translation((t_tuple){{0, 0, 0, 0}}));

	pl1->material.color = (t_tuple){{conv_color(150), conv_color(10), conv_color(10), 0}};
	pl1->material.specular = 0.1;

/* ************************************************************************** */
/*   Cylindre   cy   50,0,6   0,0,1   14.2   21.42   10,0,255		          */
/* ************************************************************************** */
	cy1 = so_new(CYLINDER, data_parsing);

	cy1->transform = multiply_matrix4(cy1->transform, rotation_x(40));
//	cy1->transform = multiply_matrix4(cy1->transform, rotation_y(5));
//	cy1->transform = multiply_matrix4(cy1->transform, rotation_z(10));
//	cy1->transform = multiply_matrix4(cy1->transform, scaling((t_tuple){{1.2, 1.2, 1.2, 0}}));
	cy1->transform = multiply_matrix4(cy1->transform, translation((t_tuple){{9, 0, 30, 0}}));

	cy1->cyl_max = 20;
	cy1->cyl_min = -20;
	cy1->cyl_closed = 1;
	cy1->material.color = (t_tuple){{conv_color(10), conv_color(255), conv_color(0), 0}};


	cy2 = so_new(CYLINDER, data_parsing);

	cy2->transform = multiply_matrix4(cy2->transform, rotation_x(90));
	cy2->transform = multiply_matrix4(cy2->transform, rotation_z(45));
	cy2->transform = multiply_matrix4(cy2->transform, translation((t_tuple){{10, 3, 20, 0}}));
	cy2->cyl_max = 10;
	cy2->cyl_min = -10;
	cy2->cyl_closed = 1;
	cy2->material.color = (t_tuple){{conv_color(80), conv_color(150), conv_color(3), 0}};

/* ************************************************************************** */

	so_add_back(&sp1, pl1);
	so_add_back(&sp1, cy1);
	so_add_back(&sp1, cy2);
	w.lst_object = sp1;

	render(all_data, c, &w);
	so_clear(&sp1);

	all_data->list_object = NULL;

	printf("%sEnd of test()%s\n", COLOR_BLUE, COLOR_RESET);
}
