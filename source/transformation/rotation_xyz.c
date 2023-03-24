/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 08:50:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	rotation_x(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[1][1] = cosf(rad);
	mtx.tab[1][2] = sinf(rad) * -1;
	mtx.tab[2][1] = sinf(rad);
	mtx.tab[2][2] = cosf(rad);
	return (mtx);
}

t_matrix4	rotation_y(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[0][0] = cosf(rad);
	mtx.tab[0][2] = sinf(rad);
	mtx.tab[2][0] = sinf(rad) * -1;
	mtx.tab[2][2] = cosf(rad);
	return (mtx);
}

t_matrix4	rotation_z(double deg)
{
	t_matrix4	mtx;
	double		rad;

	rad = deg_to_rad(deg);
	mtx = give_identity_matrix4();
	mtx.tab[0][0] = cosf(rad);
	mtx.tab[0][1] = sinf(rad) * -1;
	mtx.tab[1][0] = sinf(rad);
	mtx.tab[1][1] = cosf(rad);
	return (mtx);
}
