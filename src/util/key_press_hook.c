/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:36:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 19:33:33 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <X11/keysym.h>

// static void	awsd_shift(int keycode, t_all_data *d);
// static void	part_two(int keycode, t_all_data *d);

int	key_press_hook(int keycode, t_all_data *d)
{
	printf("%sKey pressed : %d%s\n", COLOR_MAGENTA, keycode, COLOR_RESET);
	if (keycode == XK_r)
	{
		printf("refresh image\n");
		render(&d->mlx_data, &d->camera, d->objects, &d->light);
	}
	else if (keycode == XK_Escape)
		return (mlx_loop_end(d->mlx_data.mlx), 0);
	return (0);
}

// int	key_press_hook(int keycode, t_all_data *d)
// {
// 	printf("%sKey pressed : %d%s\n", COLOR_MAGENTA, keycode, COLOR_RESET);
// 	if (keycode == 53 || keycode == 65307)
// 		return (mlx_loop_end(d->mlx_data.mlx), 0);
// 	if (keycode == 65362 || keycode == 126)
// 	{
// 		d->data_key.c_add_pos_y -= 1;
// 		d->data_key.key_up = 1;
// 	}
// 	if (keycode == 65364 || keycode == 125)
// 	{
// 		d->data_key.c_add_pos_y += 1;
// 		d->data_key.key_down = 1;
// 	}
// 	if (keycode == 111 || keycode == 31)
// 		d->data_key.c_add_fov += 0.1;
// 	if (keycode == 112 || keycode == 35)
// 		d->data_key.c_add_fov -= 0.1;
// 	awsd_shift(keycode, d);
// 	part_two(keycode, d);
// 	gen_new_img(d);
// 	return (0);
// }

// static void	part_two(int keycode, t_all_data *d)
// {
// 	(void)keycode;
// 	if (d->data_key.key_a && d->data_key.key_shift)
// 		d->data_key.c_add_to_x -= 1;
// 	if (d->data_key.key_w && d->data_key.key_shift)
// 		d->data_key.c_add_to_z += 1;
// 	if (d->data_key.key_s && d->data_key.key_shift)
// 		d->data_key.c_add_to_z -= 1;
// 	if (d->data_key.key_d && d->data_key.key_shift)
// 		d->data_key.c_add_to_x += 1;
// 	if (d->data_key.key_up && d->data_key.key_shift)
// 		d->data_key.c_add_to_y -= 1;
// 	if (d->data_key.key_down && d->data_key.key_shift)
// 		d->data_key.c_add_to_y += 1;
// }

// static void	awsd_shift(int keycode, t_all_data *d)
// {
// 	if (keycode == 97 || keycode == 0)
// 	{
// 		d->data_key.c_add_pos_x -= 1;
// 		d->data_key.key_a = 1;
// 	}
// 	if (keycode == 119 || keycode == 13)
// 	{
// 		d->data_key.c_add_pos_z += 1;
// 		d->data_key.key_w = 1;
// 	}
// 	if (keycode == 115 || keycode == 1)
// 	{
// 		d->data_key.c_add_pos_z -= 1;
// 		d->data_key.key_s = 1;
// 	}
// 	if (keycode == 100 || keycode == 2)
// 	{
// 		d->data_key.c_add_pos_x += 1;
// 		d->data_key.key_d = 1;
// 	}
// 	if (keycode == 65505 || keycode == 257)
// 		d->data_key.key_shift = 1;
// }
