/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sto_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 13:13:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	*sto_new(float t, t_object *object)
{
	t_to	*ln;

	ln = malloc(sizeof(t_to));
	if (!ln)
		return (NULL);
	ln->t = t;
	ln->object = object;
	return (ln);
}
