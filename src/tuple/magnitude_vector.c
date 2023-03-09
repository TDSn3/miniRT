/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:31:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:13:12 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

double	magnitude_vector(t_tuple const *tuple)
{
	return (sqrtf(
			tuple->x * tuple->x
			+ tuple->y * tuple->y
			+ tuple->z * tuple->z
			+ tuple->w * tuple->w));
}
