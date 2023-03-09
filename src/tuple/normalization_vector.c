/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:56:06 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/09 15:46:16 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	normalize_vector(t_tuple *tuple)
{
	*tuple = t_tuple_scale(tuple, 1 / magnitude_vector(tuple));
}

t_tuple	normalization_vector(t_tuple const *tuple)
{
	return (t_tuple_scale(tuple, 1 / magnitude_vector(tuple)));
}
