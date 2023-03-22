/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sto_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/28 15:59:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	*sto_new(double t, t_object *object)
{
	t_to	*ln;

	ln = malloc(sizeof(t_to));
	if (!ln)
		return (NULL);
	ln->t = t;
	ln->object = object;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
