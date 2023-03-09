/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:53:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 04:16:46 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <header.h>
// #include <libft.h>

// /* ************************************************************************** */
// /*                                                                            */
// /*   f.a   xy   déplace x proportionnellement à y							  */
// /*   f.b   xz   déplace x proportionnellement à z							  */
// /*   f.c   yx   déplace y proportionnellement à x							  */
// /*   f.d   yz   déplace y proportionnellement à z							  */
// /*   f.e   zx   déplace z proportionnellement à x							  */
// /*   f.f   zy   déplace z proportionnellement à y							  */
// /*                                                                            */
// /* ************************************************************************** */
// t_matrix4	*shearing(double const f[6], t_matrix4 *dst)
// {
// 	const double	m[4][4] = {
// 	{1,		f[0],	f[1],	0},
// 	{f[2],	1,		f[3],	0},
// 	{f[4],	f[5],	1,		0},
// 	{0,		0,		0,		1}
// 	};

// 	ft_memcpy(dst, m, sizeof(m));
// 	return (dst);
// }
