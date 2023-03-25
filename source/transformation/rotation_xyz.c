/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/25 16:47:05 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	rotation_x(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[1][1] = cos(rad);
	mtx.tab[1][2] = sin(rad) * -1;
	mtx.tab[2][1] = sin(rad);
	mtx.tab[2][2] = cos(rad);
	return (mtx);
}

t_matrix4	rotation_y(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[0][0] = cos(rad);
	mtx.tab[0][2] = sin(rad);
	mtx.tab[2][0] = sin(rad) * -1;
	mtx.tab[2][2] = cos(rad);
	return (mtx);
}

t_matrix4	rotation_z(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[0][0] = cos(rad);
	mtx.tab[0][1] = sin(rad) * -1;
	mtx.tab[1][0] = sin(rad);
	mtx.tab[1][1] = cos(rad);
	return (mtx);
}
