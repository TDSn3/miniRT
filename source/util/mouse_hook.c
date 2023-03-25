/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:44:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 13:28:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	mouse_hook(int mousecode, int x, int y, t_all_data *d)
{
	printf("%s%d\tx : %d\t\ty : %d%s\n",
		COLOR_ID_WHITE, mousecode, x, y, COLOR_RESET);
	(void) d;
	if (mousecode == 4)
		d->data_key->c_add_to_y += 0.02;
	if (mousecode == 5)
		d->data_key->c_add_to_y -= 0.02;
	if (mousecode == 1)
		d->data_key->c_add_to_x += 0.05;
	if (mousecode == 3)
		d->data_key->c_add_to_x -= 0.05;
	gen_new_img(d);
	return (0);
}
