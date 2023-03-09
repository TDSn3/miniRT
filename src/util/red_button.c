/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:45:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 03:29:44 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_all_data *d)
{
	printf("%sred button pressed%s\n", COLOR_ID_RED, COLOR_RESET);
	mlx_loop_end(d->mlx_data.mlx);
	return (0);
}
