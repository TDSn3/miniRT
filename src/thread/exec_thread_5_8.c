/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_thread_5_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberto <roberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:28 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/08 04:24:48 by roberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_thread5(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera->vsize)
	{
		while (dmet.x < dmet.dt->camera->hsize)
		{
			if (dmet.x % 12 == 4)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread6(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera->vsize)
	{
		while (dmet.x < dmet.dt->camera->hsize)
		{
			if (dmet.x % 12 == 5)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread7(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera->vsize)
	{
		while (dmet.x < dmet.dt->camera->hsize)
		{
			if (dmet.x % 12 == 6)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread8(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera->vsize)
	{
		while (dmet.x < dmet.dt->camera->hsize)
		{
			if (dmet.x % 12 == 7)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}
