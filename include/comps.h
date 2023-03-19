/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:46:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/19 09:53:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPS_H
# define COMPS_H

# include "struct.h"

typedef struct s_comps
{
	double		t;
	t_object	object;
	t_tuple		point;
	t_tuple		eyev_vector;
	t_tuple		normalv_vector;
	int			inside;
	t_tuple		over_point;
	double		distance;
}	t_comps;

#endif
