/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_nega.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 22:26:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	t_tuple_nega(t_tuple *tuple)
{
	tuple->x = 0 - tuple->x;
	tuple->y = 0 - tuple->y;
	tuple->z = 0 - tuple->z;
	tuple->w = 0 - tuple->w;
}
