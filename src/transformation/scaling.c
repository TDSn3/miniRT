/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:36:57 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:31:23 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_matrix4	*scaling(t_tuple vector, t_matrix4 *dst)
{
	give_identity_matrix4(dst);
	(*dst)[0][0] = vector.x;
	(*dst)[1][1] = vector.y;
	(*dst)[2][2] = vector.z;
	return (dst);
}
