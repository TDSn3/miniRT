/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exec_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:08:09 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/17 19:27:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	main_exec_thread(t_dmet *dmet)
{
	dmet -> r = ray_for_pixel(dmet -> dt -> camera, dmet -> x, dmet -> y);
	dmet -> color = color_at(dmet -> dt -> world, dmet -> r);
	dmet-> dt
		-> stock_img[dmet -> x][dmet -> y] = convert_to_255(dmet -> color);
}
