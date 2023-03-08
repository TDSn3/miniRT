/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:05:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:56:04 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_point(t_tuple *tuple, float x, float y, float z)
{
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = 1;
}
