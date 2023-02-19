/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_tuple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:14:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 16:46:41 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	copy_stock_in_a(t_tuple *a, t_tuple *stock);

void	multiply_matrix_tuple(t_tuple *a, t_matrix *left, t_tuple *right)
{
	t_tuple	stock;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	stock.tuple[0] = 0;
	stock.tuple[1] = 0;
	stock.tuple[2] = 0;
	stock.tuple[3] = 0;
	while (i < 4 && i < left->x_size)
	{
		while (j < left->y_size)
		{
			stock.tuple[i] += left->tab[i][j] * right->tuple[j];
			j++;
		}
		j = 0;
		i++;
	}
	copy_stock_in_a(a, &stock);
}

static void	copy_stock_in_a(t_tuple *a, t_tuple *stock)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		a->tuple[i] = stock->tuple[i];
		i++;
	}
}
