/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:46:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 21:41:54 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPS_H
# define COMPS_H

# include "struct.h"

typedef struct s_comps
{
	t_object	object;
	t_tuple		point;
	t_tuple		eyev_vector;
	t_tuple		normalv_vector;
	int			inside;
	t_tuple		over_point;
}	t_comps;

#endif