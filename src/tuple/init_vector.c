/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:05:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:32 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_vector(t_tuple *tuple, double x, double y, double z)
{
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = 0;
}
