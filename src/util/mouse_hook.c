/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:44:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 00:26:26 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	mouse_hook(int mousecode, int x, int y, t_all_data *d)
{
	printf("%s%d\tx : %d\t\ty : %d%s\n",
		COLOR_ID_WHITE, mousecode, x, y, COLOR_RESET);
	gen_new_img(&d->mlx_data, &d->scene);
	return (0);
}
