/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:14:46 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	define_color(t_vec3 ro, t_vec3 rd, t_vec3 pos, t_vec2 it)
{
	t_vec3	light;
	t_vec3	n;
	t_vec3	reflected;
	t_vec3	color;
	float	diffuse;
	float	specular;

	light = vec3_norm(vec3_new(0.0, -400.0, 0.0));
	n = vec3_norm(vec3_add(vec3_sub(ro, pos), vec3_mulv(rd, it.x)));
	diffuse = maxf(0.0, vec3_dot(light, n));
	reflected = reflect(vec3_norm(rd), n);
	specular = powf(maxf(0.0, vec3_dot(reflected, light)), 16.0);
	color = vec3_new(0.2, 0.3, 0.75);
	color = vec3_mulv(color, (diffuse + specular) * 0.5);
	return (color);
}

t_vec3	ray_tracing(t_vec3 ro, t_vec3 rd)
{
	t_vec2	it;

	it = draw_sphere(vec3_sub(ro, vec3_new(500.0, 0.0, 0.0)), rd, 300.0);
	if (it.x < 0.0)
	{
		return (vec3_new(0.15, 0.15, 0.20));
	}
	else
	{
		return (define_color(ro, rd, vec3_new(500, 0.0, 0.0), it));
	}
}

void	draw(t_scene scene)
{
	t_vec2	pixel;
	t_vec3	direction;
	t_vec3	col;

	pixel.y = 0.0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0.0;
		while (pixel.x < WIDTH)
		{
			direction = vec3_norm(vec3_new(scene.focus, pixel.x - WIDTH / 2.0, pixel.y - HEIGHT / 2.0));
			direction = vec3_mulmat(direction, scene.matrix);
			col = ray_tracing(scene.camera.location, direction);
			write_pixel(scene.view, pixel, col);
			pixel.x += 1.0;
		}
		pixel.y += 1.0;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}
