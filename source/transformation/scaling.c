/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 23:38:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix	*scaling(t_tuple *vector)
{
	t_matrix	*mtx;

	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[0][0] = vector->x;
	mtx->tab[1][1] = vector->y;
	mtx->tab[2][2] = vector->z;
	return (mtx);
}
