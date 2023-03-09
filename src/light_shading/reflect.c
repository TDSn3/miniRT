/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:48:49 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:52:57 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   in - ( normal * ( 2 * produit_scalaire(in, normal) ) )					  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	reflect(t_tuple in_vector, t_tuple normal_vector)
{
	t_tuple	ret;
	double	scal_prod;
	t_tuple	normal_mult_prod;

	scal_prod = 2 * scalar_product_vector(&in_vector, &normal_vector);
	normal_mult_prod = t_tuple_scale(&normal_vector, scal_prod);
	ret = t_tuple_minus(&in_vector, &normal_mult_prod);
	return (ret);
}
