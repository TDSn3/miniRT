/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:51:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 16:15:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	cross_product_vector(t_tuple *vector, t_tuple *a, t_tuple *b)
{
	t_tuple	stock;

	stock.x = a->y * b->z - a->z * b->y;
	stock.y = a->z * b->x - a->x * b->z;
	stock.z = a->x * b->y - a->y * b->x;
	vector->x = stock.x;
	vector->y = stock.y;
	vector->z = stock.z;
}
