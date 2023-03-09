/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:45:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 00:10:40 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_all_data *d)
{
	printf("window is closed using the x button\n");
	mlx_loop_end(d->mlx_data.mlx);
	return (0);
}
