/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_thread_9_12.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:05:28 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/04 19:13:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_thread9(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 8)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread10(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 9)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread11(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 10)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}

void	*exec_thread12(void *data)
{
	t_dmet	dmet;

	dmet.dt = data;
	dmet.x = 0;
	dmet.y = 0;
	while (dmet.y < dmet.dt->camera.vsize)
	{
		while (dmet.x < dmet.dt->camera.hsize)
		{
			if (dmet.x % 12 == 11)
				main_exec_thread(&dmet);
			dmet.x++;
		}
		dmet.x = 0;
		dmet.y++;
	}
	return (NULL);
}
