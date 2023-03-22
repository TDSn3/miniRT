/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:28:50 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 13:34:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	init_ambiant(t_all_data *all_data, t_dp *data_parsing)
{
	data_parsing->ambient = all_data->parsed_scene->ambient.intensity;
	data_parsing->a_color.x = conv_color(
			all_data->parsed_scene->ambient.color.r) * data_parsing->ambient;
	data_parsing->a_color.y = conv_color(
			all_data->parsed_scene->ambient.color.g) * data_parsing->ambient;
	data_parsing->a_color.z = conv_color(
			all_data->parsed_scene->ambient.color.b) * data_parsing->ambient;
	data_parsing->a_color.w = 0;
}
