/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:45:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 19:46:19 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_all_data *d)
{
	if (d -> mwi -> data_img -> img)
		mlx_destroy_image(d->mwi->mlx, d->mwi->data_img->img);
	mlx_destroy_window(d -> mwi -> mlx, d -> mwi -> win);
	mlx_destroy_display(d -> mwi -> mlx);
	free(d -> mwi -> mlx);
	// so_clear(&d->list_object);
	object_lst_clear(&d->list_object);
	exit (0);
	return (0);
}
