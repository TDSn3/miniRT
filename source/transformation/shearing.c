/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 17:54:20 by tda-silv         ###   ########.fr       */
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

t_matrix	*shearing(t_6f f)
{
	t_matrix	*mtx;

	mtx = NULL;
	mtx = new_identity_matrix();
	if (!mtx)
		return (NULL);
	mtx->tab[0][1] = f.a;
	mtx->tab[0][2] = f.b;
	mtx->tab[1][0] = f.c;
	mtx->tab[1][2] = f.d;
	mtx->tab[2][0] = f.e;
	mtx->tab[2][1] = f.f;
	return (mtx);
}
