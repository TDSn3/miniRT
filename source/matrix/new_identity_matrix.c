/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_identity_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:41:41 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 22:45:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix	*new_identity_matrix(void)
{
	t_matrix	*mtx;

	mtx = NULL;
	mtx = new_matrix(4, 4);
	if (!mtx)
		return (NULL);
	mtx->tab[0][0] = 1;
	mtx->tab[1][1] = 1;
	mtx->tab[2][2] = 1;
	mtx->tab[3][3] = 1;
	return (mtx);
}
