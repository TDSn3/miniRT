/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_xyz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:31:13 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	*rotation_x(float deg, t_matrix4 *dst)
{
	float		rad;

	rad = deg_to_rad(deg);
	give_identity_matrix4(dst);
	(*dst)[1][1] = cosf(rad);
	(*dst)[1][2] = sinf(rad) * -1;
	(*dst)[2][1] = sinf(rad);
	(*dst)[2][2] = cosf(rad);
	return (dst);
}

t_matrix4	*rotation_y(float deg, t_matrix4 *dst)
{
	float		rad;

	rad = deg_to_rad(deg);
	give_identity_matrix4(dst);
	(*dst)[0][0] = cosf(rad);
	(*dst)[0][2] = sinf(rad);
	(*dst)[2][0] = sinf(rad) * -1;
	(*dst)[2][2] = cosf(rad);
	return (dst);
}

t_matrix4	*rotation_z(float deg, t_matrix4 *dst)
{
	float		rad;

	rad = deg_to_rad(deg);
	give_identity_matrix4(dst);
	(*dst)[0][0] = cosf(rad);
	(*dst)[0][1] = sinf(rad) * -1;
	(*dst)[1][0] = sinf(rad);
	(*dst)[1][1] = cosf(rad);
	return (dst);
}
