/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:13:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 17:41:44 by tda-silv         ###   ########.fr       */
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
/*   transform(&point2, translation(&vect), &point);						  */
/*   transform(&point2, scaling(&vect), &point);							  */
/*   transform(&point2, inverse_matrix_free(scaling(&vect)), &point);		  */
/*   transform(&point2, rotation_x(45), &point);							  */
/*   transform(&point2, shearing((t_xyz){0, 1, 0, 0, 0, 0}), &point);		  */
/*                                                                            */
/* ************************************************************************** */
void	transform(t_tuple *dst, t_matrix *mtx, t_tuple *point)
{
	multiply_matrix_tuple(dst, mtx, point);
	free(mtx);
}
