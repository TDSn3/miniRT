/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 20:06:41 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   f.a   xy   déplace x proportionnellement à y							  */
/*   f.b   xz   déplace x proportionnellement à z							  */
/*   f.c   yx   déplace y proportionnellement à x							  */
/*   f.d   yz   déplace y proportionnellement à z							  */
/*   f.e   zx   déplace z proportionnellement à x							  */
/*   f.f   zy   déplace z proportionnellement à y							  */
/*                                                                            */
/* ************************************************************************** */
t_matrix4	*shearing(float f[6], t_matrix4 *dst)
{
	give_identity_matrix4(dst);
	(*dst)[0][1] = f[0];
	(*dst)[0][2] = f[1];
	(*dst)[1][0] = f[2];
	(*dst)[1][2] = f[3];
	(*dst)[2][0] = f[4];
	(*dst)[2][1] = f[5];
	return (dst);
}
