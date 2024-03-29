/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/02 15:01:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_intersection	*si_new(t_3f t, t_object *object)
{
	t_intersection	*ln;

	ln = malloc(sizeof(t_intersection));
	if (!ln)
		return (NULL);
	ln->t = t;
	ln->object = object;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
