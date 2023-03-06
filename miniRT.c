/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:58:01 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/04 17:55:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(void)
{
	t_all_data		all_data;
	t_mwi			mwi;
	t_data_mlx_img	data_img;
	t_dk			data_key;

	init_all(&all_data, &mwi, &data_img, &data_key);
	mlx_hook(mwi.win, 17, 0L, red_button, &all_data);
	mlx_hook(mwi.win, 2, 1L << 0L, key_press_hook, &all_data);
	mlx_hook(mwi.win, 3, 1L << 1L, key_release_hook, &all_data);
	mlx_mouse_hook(mwi.win, mouse_hook, &all_data);
	mlx_loop_hook(mwi.mlx, gen_new_img, &all_data);
	mlx_loop(mwi.mlx);
	return (0);
}
