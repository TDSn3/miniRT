/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_multi_scal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:28:35 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Multiplie un tuple par un scalaire.									  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	t_tuple_multi_scal(t_tuple left, double right)
{
	t_tuple	ret;

	ret.x = left.x * right;
	ret.y = left.y * right;
	ret.z = left.z * right;
	ret.w = left.w * right;
	return (ret);
}
