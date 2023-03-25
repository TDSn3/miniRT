/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:56:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/25 18:26:11 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>

int	valid_orientation(t_parsed_vector orientation)
{
	double	norm;

	if (isnan(orientation.x) || isnan(orientation.y) || isnan(orientation.z))
		return (0);
	if (!orientation.x && !orientation.y && !orientation.z)
		return (0);
	if (fabs(orientation.x) > 1 || fabs(orientation.y) > 1
		|| fabs(orientation.z) > 1)
		return (0);
	norm = sqrt(pow(orientation.x, 2) + pow(orientation.y, 2)
			+ pow(orientation.z, 2));
	if (norm < 1 - EPSILON || norm > 1 + EPSILON)
	{
		if (STRICT_NORMALIZATION_CHECK)
			return (0);
		printf("Warning: orientation vector will be automatically normalized");
		printf(" (norm is %f)\n", norm);
	}
	return (1);
}

t_parsed_vector	parse_vec3(char *item)
{
	double					x;
	double					y;
	double					z;
	char					**tokens;
	const t_parsed_vector	invalid
		= (t_parsed_vector){.x = NAN, .y = NAN, .z = NAN};

	tokens = ft_split(item, ',');
	if (!tokens)
		return (invalid);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), invalid);
	x = ft_atod(tokens[0]);
	y = ft_atod(tokens[1]);
	z = ft_atod(tokens[2]);
	if (isnan(x) || isnan(y) || isnan(z))
		return (free_tokens(tokens), invalid);
	return (free_tokens(tokens), (t_parsed_vector){.x = x, .y = y, .z = z});
}

t_parsed_color	parse_color(char *item)
{
	char					**tokens;
	int						r;
	int						g;
	int						b;
	const t_parsed_color	invalid = (t_parsed_color){.a = 255};

	tokens = ft_split(item, ',');
	if (!tokens)
		return (invalid);
	if (count_tokens(tokens) != 3)
		return (free_tokens(tokens), invalid);
	r = ft_atouc(tokens[0]);
	g = ft_atouc(tokens[1]);
	b = ft_atouc(tokens[2]);
	if (r == -1 || g == -1 || b == -1)
		return (free_tokens(tokens), invalid);
	return (free_tokens(tokens),
		(t_parsed_color){.a = 0, .r = r, .g = g, .b = b});
}

int	is_invalid(const t_parameter type, void *param)
{
	if (type == DEC)
		return (isnan(*(double *)param));
	else if (type == DEC_3)
		return (isnan(((t_parsed_vector *)param)->x)
			|| isnan(((t_parsed_vector *)param)->y)
			|| isnan(((t_parsed_vector *)param)->z));
	else if (type == COLOR)
		return (((t_parsed_color *)param)->a == 255);
	return (1);
}

int	parse_items(int n, char **tokens, const t_parameter *syntax, void **params)
{
	int	i;

	if (count_tokens(tokens) != n)
		return (1);
	i = -1;
	while (++i < n)
	{
		if (syntax[i] == DEC)
			*(double *)params[i] = ft_atod(tokens[i]);
		else if (syntax[i] == DEC_3)
			*(t_parsed_vector *)params[i] = parse_vec3(tokens[i]);
		else if (syntax[i] == COLOR)
			*(t_parsed_color *)params[i] = parse_color(tokens[i]);
		else
			return (1);
		if (is_invalid(syntax[i], params[i]))
			return (1);
	}
	if (tokens[i])
		return (1);
	return (0);
}
