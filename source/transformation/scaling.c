/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:37:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	scaling(t_tuple vector)
{
	t_matrix4	mtx;

	mtx = give_identity_matrix4();
	mtx.tab[0][0] = vector.x;
	mtx.tab[1][1] = vector.y;
	mtx.tab[2][2] = vector.z;
	return (mtx);
}
