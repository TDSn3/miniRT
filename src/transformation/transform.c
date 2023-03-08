/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 06:19:31 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   t_tuple	vect;														  */
/*   t_tuple	point;														  */
/*   t_tuple	point2;														  */
/*                                                                            */
/*   init_vector(&vect, 5, -3, 2);											  */
/*   init_point(&point, -3, 4, 5);											  */
/*   init_point(&point2, 0, 0, 0);											  */
/*   point2 = transform(translation(&vect), &point);			 			  */
/*   point2 = transform(scaling(&vect), &point);							  */
/*   point2 = transform(inverse_matrix_free(scaling(&vect)), &point);		  */
/*   point2 = transform(rotation_x(45), &point);							  */
/*   point2 = transform(shearing((t_xyz){0, 1, 0, 0, 0, 0}), &point);		  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	transform(t_matrix4 const *mtx, t_tuple point)
{
	t_tuple	stock;

	stock = multiply_matrix4_tuple(mtx, point);
	return (stock);
}
