/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:27:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/22 15:05:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	init_matrix4_orientation(t_matrix4 *orientation);

/* ************************************************************************** */
/*                                                                            */
/*   from   position de la camera											  */
/*   to     direction de la camera											  */
/*   up     direction vers le haut de la camera								  */
/*                                                                            */
/* ************************************************************************** */
t_matrix4	view_transform(t_tuple from, t_tuple to)
{
	t_matrix4	orientation;

	printf("%f %f %f\n", to.x, to.y, to.z);
	init_matrix4_orientation(&orientation);
	orientation = multiply_matrix4(orientation, rotation_x(to.x));
	orientation = multiply_matrix4(orientation, rotation_y(to.y));
	orientation = multiply_matrix4(orientation, rotation_z(to.z));
	orientation = multiply_matrix4(
			orientation, translation(t_tuple_nega(from)));
	return (orientation);
}

static void	init_matrix4_orientation(t_matrix4 *orientation)
{
	*orientation = (t_matrix4){0};
	orientation->tab[0][0] = -1;
	orientation->tab[1][1] = 1;
	orientation->tab[2][2] = -1;
	orientation->tab[3][3] = 1;
}
