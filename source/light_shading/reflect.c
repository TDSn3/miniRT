/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:48:49 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 16:53:16 by tda-silv         ###   ########.fr       */
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
	normal_mult_prod = t_tuple_multi_scal(normal_vector, scal_prod);
	ret = t_tuple_minus(in_vector, normal_mult_prod);
	return (ret);
}
