/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:05:37 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:08:23 by tda-silv         ###   ########.fr       */
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
