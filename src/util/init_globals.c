/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_globals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 05:17:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/10 06:20:23 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <header.h>

int	init_camera(t_camera *camera, t_parsed_camera *parsed_camera)
{
	*camera = give_camera(parsed_camera->fov_degrees);
	// TODO: set camera position and direction from parsed_camera
	return (0);
}

int	init_light(t_light *light, t_parsed_light *parsed_light)
{
	*light = (t_light){
		.position = {
		.x = parsed_light->position.x,
		.y = parsed_light->position.y,
		.z = parsed_light->position.z,
		.w = 1,},
		.intensity = {
		.x = parsed_light->intensity,
		.y = parsed_light->intensity,
		.z = parsed_light->intensity,
		.w = 0,},
	};
	return (0);
}
