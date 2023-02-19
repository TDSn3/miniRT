/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:41:44 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/19 17:42:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	free_matrix(t_matrix *a)
{
	size_t	i;

	i = 0;
	if (a && a->tab && *a->tab)
		while (i < a->y_size && a->tab[i])
			free(a->tab[i++]);
	if (a && a->tab)
		free(a->tab);
	return (1);
}
