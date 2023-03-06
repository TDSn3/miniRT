/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcatini <rcatini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 03:56:35 by roberto           #+#    #+#             */
/*   Updated: 2023/03/06 16:10:33 by rcatini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>
#include <parser.h>
#include <libft.h>

t_3f	parse_vec3(char *item)
{
	double		x;
	double		y;
	double		z;
	char		**tokens;
	const t_3f	invalid = (t_3f){.a = NAN, .b = NAN, .c = NAN};

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
	return (free_tokens(tokens), (t_3f){.a = x, .b = y, .c = z});
}

t_bgra	parse_color(char *item)
{
	char			**tokens;
	int				r;
	int				g;
	int				b;
	const t_bgra	invalid = (t_bgra){.a = 255};

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
	return (free_tokens(tokens), (t_bgra){.a = 0, .r = r, .g = g, .b = b});
}

int	is_invalid(const t_parameter type, void *param)
{
	if (type == DEC)
		return (isnan(*(double *)param));
	else if (type == DEC_3)
		return (isnan(((t_3f *)param)->a) || isnan(((t_3f *)param)->b)
			|| isnan(((t_3f *)param)->c));
	else if (type == COLOR)
		return (((t_bgra *)param)->a == 255);
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
			*(t_3f *)params[i] = parse_vec3(tokens[i]);
		else if (syntax[i] == COLOR)
			*(t_bgra *)params[i] = parse_color(tokens[i]);
		else
			return (1);
		if (is_invalid(syntax[i], params[i]))
			return (1);
	}
	if (tokens[i])
		return (1);
	return (0);
}
