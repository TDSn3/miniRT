/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:23:17 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 23:34:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	set_transform(t_object *object, t_matrix *t)
{
	object->transform = &t;
}
