/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:43:34 by tda-silv          #+#    #+#             */
/*   Updated: 2023/03/16 15:11:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	exec_all_thread_main(t_dt *dt, pthread_t *t, int i, int *err);
static int	exec_all_thread(t_dt *dt);
static int	return_err(void);

void	render(t_all_data *all_data, t_camera camera, t_world *world)
{
	t_dt	dt;
	size_t	x;
	size_t	y;

	dt.all_data = all_data;
	dt.camera = camera;
	dt.world = world;
	exec_all_thread(&dt);

	x = 0;
	y = 0;
	while (y < camera.vsize)
	{
		while (x < camera.hsize)
		{
			my_mlx_pixel_put(all_data, x - camera.hsize / 2,
				y - camera.vsize / 2, dt.stock_img[x][y].bgra);
			x++;
		}
		x = 0;
		y++;
	}
}

static int	exec_all_thread(t_dt *dt)
{
	pthread_t	t[12];
	int			err;
	int			i;

	i = 0;
	while (i < 12)
	{
		exec_all_thread_main(dt, &t[i], i, &err);
		if (err)
			return (return_err());
		i++;
	}
	i = 0;
	while (i < 12)
	{
		printf("%sthread %d%s\n", COLOR_BOLD_RED, i, COLOR_RESET);
//		pthread_join(t[i++], NULL);
		pthread_join(t[0], NULL);
		i++;
	}
	return (0);
}

static void	exec_all_thread_main(t_dt *dt, pthread_t *t, int i, int *err)
{
	if (i % 12 == 0)
		*err = pthread_create(t, NULL, exec_thread1, (void *) dt);
	//else if (i % 12 == 1)
	//	*err = pthread_create(t, NULL, exec_thread2, (void *) dt);
	//else if (i % 12 == 2)
	//	*err = pthread_create(t, NULL, exec_thread3, (void *) dt);
	//else if (i % 12 == 3)
	//	*err = pthread_create(t, NULL, exec_thread4, (void *) dt);
	//else if (i % 12 == 4)
	//	*err = pthread_create(t, NULL, exec_thread5, (void *) dt);
	//else if (i % 12 == 5)
	//	*err = pthread_create(t, NULL, exec_thread6, (void *) dt);
	//else if (i % 12 == 6)
	//	*err = pthread_create(t, NULL, exec_thread7, (void *) dt);
	//else if (i % 12 == 7)
	//	*err = pthread_create(t, NULL, exec_thread8, (void *) dt);
	//else if (i % 12 == 8)
	//	*err = pthread_create(t, NULL, exec_thread9, (void *) dt);
	//else if (i % 12 == 9)
	//	*err = pthread_create(t, NULL, exec_thread10, (void *) dt);
	//else if (i % 12 == 10)
	//	*err = pthread_create(t, NULL, exec_thread11, (void *) dt);
	//else
	//	*err = pthread_create(t, NULL, exec_thread12, (void *) dt);
}

static int	return_err(void)
{
	printf("Error : thread no createdn\n");
	return (1);
}
