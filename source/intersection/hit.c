/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:29:38 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/25 13:19:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_to	hit(t_intersection *list)
{
	t_to			ret;
	t_intersection	*copysi;

	copysi = list;
	if (!list)
		return ((t_to){NAN, NULL, NULL, NULL});
	ret.t = FLT_MAX;
	while (copysi)
	{
		if (copysi->t.b < ret.t && copysi->t.b >= 0)
		{
			ret.t = copysi->t.b;
			ret.object = copysi->object;
		}
		if (copysi->t.c < ret.t && copysi->t.c >= 0)
		{
			ret.t = copysi->t.c;
			ret.object = copysi->object;
		}
		copysi = copysi->next;
	}
	return (ret);
}

t_to	*hit_to(t_to *list)
{
	t_to	*ret;
	t_to	*copyto;

	ret = calloc(1, sizeof(t_to));
	copyto = list;
	if (!list)
		return (NULL);
	ret->t = FLT_MAX;
	ret->object = NULL;
	ret->prev = NULL;
	ret->next = NULL;



	int	ok = 0;
	for (t_to *cpy2 = list; cpy2; cpy2 = cpy2->next)
	{
		if (cpy2->t)
		{
			printf("%f   ", cpy2->t);
			ok = 1;
		}
	}
	if (ok)
		printf("\n");




	ok = 0;
	for (t_to *cpy2 = list; cpy2; cpy2 = cpy2->next)
		if (cpy2->t)
			ok = 1;
	if (!ok)
	{
		ret->t = 0;
		return (ret);
	}



	int	i = 0;
	while (copyto)
	{
		printf("%d : %s%f   %s", i, COLOR_YELLOW, copyto->t, COLOR_RESET);
		if (copyto->t < ret->t && copyto->t > 0)
		{
			ret->t = copyto->t;	
			ret->object = copyto->object;
			printf("%s%f   %s", COLOR_BLUE, ret->t, COLOR_RESET);
			printf("%s%f   %s", COLOR_RED, copyto->t, COLOR_RESET);
		}
		i++;
		copyto = copyto->next;
	}



	if (ret->t)
		printf("-->%f ", ret->t);

	return (ret);
}
