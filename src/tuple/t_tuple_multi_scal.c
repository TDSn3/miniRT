/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_multi_scal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/10 21:29:49 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <assert.h>

/* ************************************************************************** */
/*                                                                            */
/*   Multiplie un tuple par un scalaire.									  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	t_tuple_scale(t_tuple const *left, double right)
{
	assert(left->w == 0);
	return ((t_tuple){{
			left->x * right,
			left->y * right,
			left->z * right,
			left->w * right}});
}
