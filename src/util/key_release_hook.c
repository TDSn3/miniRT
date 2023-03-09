/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:36:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 03:00:32 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   mac || linux                                                             */
/*                                                                            */
/*    53 || 65307     esc													  */
/*     0 ||    97      A													  */
/*    13 ||   119      W													  */
/*     1 ||   115      S													  */
/*     2 ||   100      D													  */
/*                                          	                          	  */
/*    31 ||   111      O													  */
/*    35 ||   112      P													  */
/*                                          	                          	  */
/*   257 || 65505    shift													  */
/*                                                                            */
/*   123 || 65361      ←													  */
/*   126 || 65362      ↑													  */
/*   125 || 65364      ↓													  */
/*   124 || 65363      →													  */
/*                                                                      	  */
/* ************************************************************************** */
int	key_release_hook(int keycode, t_all_data *d)
{
	if (keycode == 97 || keycode == 0)
		d->data_key.key_a = 0;
	if (keycode == 119 || keycode == 13)
		d->data_key.key_w = 0;
	if (keycode == 115 || keycode == 1)
		d->data_key.key_s = 0;
	if (keycode == 100 || keycode == 2)
		d->data_key.key_d = 0;
	if (keycode == 65362 || keycode == 126)
		d->data_key.key_up = 0;
	if (keycode == 65364 || keycode == 125)
		d->data_key.key_down = 0;
	if (keycode == 65505 || keycode == 257)
		d->data_key.key_shift = 0;
	return (0);
}
