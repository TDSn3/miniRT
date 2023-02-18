/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_nega.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:45:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	t_tuple_nega(t_tuple *tuple)
{
	tuple->x = tuple->x * -1;
	tuple->y = tuple->y * -1;
	tuple->z = tuple->z * -1;
	tuple->w = tuple->w * -1;
}
