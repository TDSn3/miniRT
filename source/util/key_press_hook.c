/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:36:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 13:34:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	awsd_shift(int keycode, t_all_data *d);
static void	part_two(t_all_data *d);
static void	part_three(t_all_data *d);

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mac || linux                                                             */
/*                                                                            */
/*    53 || 65307     esc													  */
/*     0 ||    97      A													  */
/*    13 ||   119      W													  */
/*     1 ||   115      S													  */
/*     2 ||   100      D													  */
/*                                          	                          	  */
/*    31 ||   111      O													  */
/*    35 ||   112      P													  */
/*                                          	                          	  */
/*   257 || 65505    shift													  */
/*                                                                            */
/*   123 || 65361      ←													  */
/*   126 || 65362      ↑													  */
/*   125 || 65364      ↓													  */
/*   124 || 65363      →													  */
/*                                                                      	  */
/* ************************************************************************** */
int	key_press_hook(int keycode, t_all_data *d)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_loop_end(d->mwi->mlx);
		return (0);
	}
	printf("%sKey pressed : %d%s\n", COLOR_MAGENTA, keycode, COLOR_RESET);
	if (keycode == 65362 || keycode == 126)
	{
		d->data_key->c_add_pos_y += 1;
		d->data_key->key_up = 1;
	}
	if (keycode == 65364 || keycode == 125)
	{
		d->data_key->c_add_pos_y -= 1;
		d->data_key->key_down = 1;
	}
	if (keycode == 111 || keycode == 31)
		d->data_key->c_add_fov += 1;
	if (keycode == 112 || keycode == 35)
		d->data_key->c_add_fov -= 1;
	awsd_shift(keycode, d);
	part_two(d);
	gen_new_img(d);
	return (0);
}

static void	part_two(t_all_data *d)
{
	if (d->data_key->key_a && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_x += 1;
		d->data_key->c_add_to_x += 0.02;
	}
	if (d->data_key->key_w && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_z -= 1;
		d->data_key->c_add_to_z += 0.02;
	}
	part_three(d);
}

static void	part_three(t_all_data *d)
{
	if (d->data_key->key_s && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_z += 1;
		d->data_key->c_add_to_z -= 0.02;
	}
	if (d->data_key->key_d && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_x -= 1;
		d->data_key->c_add_to_x -= 0.02;
	}
	if (d->data_key->key_up && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_y -= 1;
		d->data_key->c_add_to_y += 0.02;
	}
	if (d->data_key->key_down && d->data_key->key_shift)
	{
		d->data_key->c_add_pos_y += 1;
		d->data_key->c_add_to_y -= 0.02;
	}
}

static void	awsd_shift(int keycode, t_all_data *d)
{
	if (keycode == 97 || keycode == 0)
	{
		d->data_key->c_add_pos_x -= 1;
		d->data_key->key_a = 1;
	}
	if (keycode == 119 || keycode == 13)
	{
		d->data_key->c_add_pos_z += 1;
		d->data_key->key_w = 1;
	}
	if (keycode == 115 || keycode == 1)
	{
		d->data_key->c_add_pos_z -= 1;
		d->data_key->key_s = 1;
	}
	if (keycode == 100 || keycode == 2)
	{
		d->data_key->c_add_pos_x += 1;
		d->data_key->key_d = 1;
	}
	if (keycode == 65505 || keycode == 257)
		d->data_key->key_shift = 1;
}
