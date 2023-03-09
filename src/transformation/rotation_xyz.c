/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:53:53 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#undef __STRICT_ANSI__
#include <header.h>

t_matrix4	*rotation_x(double deg, t_matrix4 *dst)
{
	double		rad;

	rad = deg * M_PI / 180.0;
	identity_matrix(4, (double *)dst);
	(*dst)[1][1] = cosf(rad);
	(*dst)[1][2] = sinf(rad) * -1;
	(*dst)[2][1] = sinf(rad);
	(*dst)[2][2] = cosf(rad);
	return (dst);
}

t_matrix4	*rotation_y(double deg, t_matrix4 *dst)
{
	double		rad;

	rad = deg * M_PI / 180.0;
	identity_matrix(4, (double *)dst);
	(*dst)[0][0] = cosf(rad);
	(*dst)[0][2] = sinf(rad);
	(*dst)[2][0] = sinf(rad) * -1;
	(*dst)[2][2] = cosf(rad);
	return (dst);
}

t_matrix4	*rotation_z(double deg, t_matrix4 *dst)
{
	double		rad;

	rad = deg * M_PI / 180.0;
	identity_matrix(4, (double *)dst);
	(*dst)[0][0] = cosf(rad);
	(*dst)[0][1] = sinf(rad) * -1;
	(*dst)[1][0] = sinf(rad);
	(*dst)[1][1] = cosf(rad);
	return (dst);
}
