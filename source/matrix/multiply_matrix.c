/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:14:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 18:09:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Attention, "a" doit être différent de "left" et "right".				  */
/*                                                                            */
/* ************************************************************************** */
void	multiply_matrix(t_matrix *a, t_matrix *left, t_matrix *right)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < left->x_size)
	{
		while (j < right->y_size)
		{
			a->tab[i][j] = 0;
			while (k < left->y_size)
			{
				a->tab[i][j] += left->tab[i][k] * right->tab[k][j];
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
