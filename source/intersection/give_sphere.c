/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 02:45:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/20 21:14:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_object	give_sphere(unsigned int id, t_tuple position)
{
	t_object	new_sphere;

	new_sphere.id = id;
	new_sphere.position = position;
	return (new_sphere);
}
