/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:05:24 by rcatini           #+#    #+#             */
/*   Updated: 2023/02/28 10:45:24 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*parse_byte(char *line, unsigned char *target)
{
	if (sscanf(line, "%hhu", target) != 1)
		return (NULL);
	return (line);
}

int	parse_line(char *line, int arg_count, t_parameter *args, void *targets)
{
	int		i;
	char	**items;

	items = ft_split(line, ' ');
	i = -1;
	while (++i < arg_count)
	{
		line = skip_whitespace(line);
		if (args[i] == BYTE)
			line = parse_byte(line, targets);
		else if (args[i] == BYTE_3)
			line = parse_byte_3(line, targets);
		else if (args[i] == DECIMAL)
			line = parse_decimal(line, targets);
		else if (args[i] == DECIMAL_3)
			line = parse_decimal_3(line, targets);
		else if (args[i] == INTEGER)
			line = parse_integer(line, targets);
		else if (args[i] == INTEGER_3)
			line = parse_integer_3(line, targets);
		else
			return (-i);
	}
	if (skip_whitespace(line) != '\0')
		return (INT_MIN);
}
