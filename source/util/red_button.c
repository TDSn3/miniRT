/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:45:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 15:28:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_all_data *d)
{
	if (d -> mwi -> data_img -> img)
		mlx_destroy_image(d->mwi->mlx, d->mwi->data_img->img);
	mlx_destroy_window(d -> mwi -> mlx, d -> mwi -> win);
//	mlx_destroy_display(d -> mwi -> mlx); // <------- Ok sur Linux mais pas sur MacOs
	free(d -> mwi -> mlx);
	exit (0);
	return (0);
}
