/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:46:14 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:24:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	translation(t_tuple vector)
{
	t_matrix4	mtx;

	mtx = give_identity_matrix4();
	mtx.tab[0][3] = vector.x;
	mtx.tab[1][3] = vector.y;
	mtx.tab[2][3] = vector.z;
	return (mtx);
}
