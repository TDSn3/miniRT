/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 07:31:33 by roberto          ###   ########.fr       */
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
t_matrix4	*shearing(t_6f f, t_matrix4 *dst)
{
	give_identity_matrix4(dst);
	(*dst)[0][1] = f.a;
	(*dst)[0][2] = f.b;
	(*dst)[1][0] = f.c;
	(*dst)[1][2] = f.d;
	(*dst)[2][0] = f.e;
	(*dst)[2][1] = f.f;
	return (dst);
}
