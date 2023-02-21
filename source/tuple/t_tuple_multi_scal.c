/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tuple_multi_scal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:12:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/21 16:11:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Multiplie un tuple par un scalaire.									  */
/*                                                                            */
/* ************************************************************************** */
t_tuple	t_tuple_multi_scal(t_tuple left, float right)
{
	t_tuple	ret;

	ret.x = left.x * right;
	ret.y = left.y * right;
	ret.z = left.z * right;
	ret.w = left.w * right;
	return (ret);
}
