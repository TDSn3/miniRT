/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:35 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/22 19:48:10 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_parse_file(char *file, t_world *world)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_parse_line(line, world) == 0)
			return (0);
		free(line);
	}
	if (ret == -1)
		return (0);
	close(fd);
	return (1);
}
