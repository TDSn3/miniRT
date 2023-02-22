/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 14:09:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_object	*so_new(unsigned int id, t_type type)
{
	t_object	*ln;

	ln = malloc(sizeof(t_object));
	if (!ln)
		return (NULL);

	ln->id = id;
	ln->type = type;
	ln->position = (t_tuple){{0, 0, 0, 1}};
	ln->transform = new_identity_matrix();
	ln->material.color = (t_tuple){{1, 0.2, 1, 0}};
	ln->material.ambient = 0.1;
	ln->material.diffuse = 0.9;
	ln->material.specular = 0.9;
	ln->material.shininess = 200;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
