/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:35 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/22 22:49:17 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*parse_line(char *line, t_world *scene)
{
	if (!ft_strncmp(line, "\n", 2))
		return (0);
	if (!ft_strncmp(line, "A ", 2))
		return (parse_ambient(scene, line + 2));
	if (!ft_strncmp(line, "C ", 2))
		return (parse_camera(scene, line + 2));
	if (!ft_strncmp(line, "L ", 2))
		return (parse_light(scene, line + 2));
	if (!ft_strncmp(line, "sp ", 3))
		return (parse_sphere(scene, line + 3));
	if (!ft_strncmp(line, "pl ", 3))
		return (parse_plane(scene, line + 3));
	if (!ft_strncmp(line, "cy ", 3))
		return (parse_cylinder(scene, line + 3));
	return ("Error: Invalid line\n");
}

char	*parse_scene(char *filename, t_world *scene)
{
	int		fd;
	char	*line;
	char	*error_msg;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (strerror(errno));
	line = get_next_line(fd);
	while (line)
	{
		error_msg = parse_line(line, scene);
		free(line);
		if (error_msg)
			return (error_msg);
		line = get_next_line(fd);
	}
	close(fd);
	return (NULL);
}
