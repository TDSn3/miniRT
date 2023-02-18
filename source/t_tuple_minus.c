/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/18 17:17:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	t_tuple_minus(t_tuple *left, t_tuple *right)
{
	left->x = left->x - right->x;
	left->y = left->y - right->y;
	left->z = left->z - right->z;
	left->w = left->w - right->w;
}
