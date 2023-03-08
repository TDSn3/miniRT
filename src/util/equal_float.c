/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:32:14 by roberto           #+#    #+#             */
/*   Updated: 2023/03/08 21:32:19 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   Test l'équivalence de deux double à l'aide d'EPSILON.					  */
/*                                                                            */
/* ************************************************************************** */
inline int	equal_float(double a, double b)
{
	if ((a - b) < EPSILON)
		return (1);
	else
		return (0);
}
