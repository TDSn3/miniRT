/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/24 15:58:33 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_object	*so_new(t_type type, t_dp dp)
{
	t_object	*ln;

	ln = malloc(sizeof(t_object));
	if (!ln)
		return (NULL);
	ln->type = type;
	ln->position = (t_tuple){{0, 0, 0, 1}};
	ln->transform = give_identity_matrix4();
	// ln->cyl_min = -INFINITY;
	// ln->cyl_max = INFINITY;
	ln->cyl_closed = 0;
	ln->material.color = (t_tuple){{1, 0.2, 1, 0}};
	ln->material.ambient = dp.ambient;
	ln->material.a_color = dp.a_color;
	ln->material.diffuse = 0.9;
	ln->material.specular = 0.9;
	ln->material.shininess = 200;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
