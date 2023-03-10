/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_product_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:27:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:27:11 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

/* ************************************************************************** */
/*                                                                            */
/*   Ou "dot product".														  */
/*                                                                            */
/* ************************************************************************** */
double	scalar_product_vector(t_tuple *a, t_tuple *b)
{
	assert(a->w == 0 && b->w == 0);
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w));
}
