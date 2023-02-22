/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_canvas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:54:04 by tda-silv          #+#    #+#             */
/*   Updated: 2023/02/22 23:34:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   ray_origin            origine du rayon									  */
/*   r                     rayon											  */
/*   position_point_wall   point sur le mur que le rayon ciblera              */
/*                                                                            */
/* ************************************************************************** */
void	print_canvas(t_all_data *all_data)
{
	t_object		shape;

	shape.id = 1;
	shape.type = SPHERE;
	shape.position = (t_tuple){{0, 0, 0, 1}};
	shape.transform = give_identity_matrix4();

	shape.material.color = (t_tuple){{1, 0.2, 1, 0}};
	shape.material.ambient = 0.1;
	shape.material.diffuse = 0.9;
	shape.material.specular = 0.9;
	shape.material.shininess = 200;

	t_tuple			ray_origin;
	float			wall_z;
	float			wall_size;
	float			canvas_pixels;
	float			pixel_size;
	float			half;
	float			world_x;
	float			world_y;
	size_t			x;
	size_t			y;

	t_intersection	list_intersection;
	t_tuple			position_point_wall;
	t_ray			r;
	t_to			list_hit;

	t_light			light;
	t_tuple			point;
	t_tuple			normal;
	t_tuple			eye;
	t_tuple			color;

	ray_origin = (t_tuple){{0, 0, -5, 1}};
	wall_z = 10;
	wall_size = 7;
	canvas_pixels = 200;
	pixel_size = wall_size / canvas_pixels;
	half = wall_size / 2;
	world_x = 0;
	world_y = 0;
	x = 0;
	y = 0;
	r.point = ray_origin;

	light.position = (t_tuple){{-10, -10, -10, 1}};
	light.intensity = (t_tuple){{1, 1, 1, 0}};

	while (y < canvas_pixels)
	{
		world_y = half - pixel_size * y;
		while (x < canvas_pixels)
		{
			world_x = -half + pixel_size * x;
			init_point(&position_point_wall, world_x, world_y, wall_z);
			r.vector = normalization_vector(t_tuple_minus(position_point_wall, ray_origin));
			list_intersection = intersect(r.vector, r.point, &shape);
			list_hit = hit(&list_intersection);
			if (list_hit.t)
			{
				point = position(r.vector, r.point, list_hit.t);
				normal = normal_at(*list_hit.object, point);
				eye = t_tuple_nega(r.vector);
				color = lighting(list_hit.object->material, light, point, eye, normal);
				my_mlx_pixel_put(all_data, x - canvas_pixels / 2, y - canvas_pixels / 2, convert_to_255(color).bgra);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
