/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 01:13:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 01:39:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix	*rotation_x(float deg)
{
	t_matrix	*mtx;
	float		rad;

	rad = deg_to_rad(deg);
	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[1][1] = cosf(rad);
	mtx->tab[1][2] = sinf(rad) * -1;
	mtx->tab[2][1] = sinf(rad);
	mtx->tab[2][2] = cosf(rad);
	return (mtx);
}

t_matrix	*rotation_y(float deg)
{
	t_matrix	*mtx;
	float		rad;

	rad = deg_to_rad(deg);
	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[0][0] = cosf(rad);
	mtx->tab[0][2] = sinf(rad);
	mtx->tab[2][0] = sinf(rad) * -1;
	mtx->tab[2][2] = cosf(rad);
	return (mtx);
}

t_matrix	*rotation_z(float deg)
{
	t_matrix	*mtx;
	float		rad;

	rad = deg_to_rad(deg);
	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[0][0] = cosf(rad);
	mtx->tab[0][1] = sinf(rad) * -1;
	mtx->tab[1][0] = sinf(rad);
	mtx->tab[1][1] = cosf(rad);
	return (mtx);
}
