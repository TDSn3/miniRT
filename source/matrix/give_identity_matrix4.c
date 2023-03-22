/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_identity_matrix4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:41:41 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 22:13:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	give_identity_matrix4(void)
{
	t_matrix4	mtx;

	mtx = (t_matrix4){0};
	mtx.tab[0][0] = 1;
	mtx.tab[1][1] = 1;
	mtx.tab[2][2] = 1;
	mtx.tab[3][3] = 1;
	return (mtx);
}
