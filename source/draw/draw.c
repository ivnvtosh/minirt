/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/01 01:47:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	at(t_ray ray, float t)
{
	return (vec3_add(ray.origin, vec3_mulv(ray.direction, t)));
}

t_ray	get_ray(t_vec2 pixel, t_cam camera, t_mat matrix)
{
	t_ray	ray;

	ray.origin = camera.location;
	pixel.x -= WIDTH / 2.0;
	pixel.y -= HEIGHT / 2.0;
	ray.direction = vec3_norm(vec3_new(camera.focus, pixel.x, pixel.y));
	ray.direction = vec3_mulmat(ray.direction, matrix);
	return (ray);
}

void	__draw(t_view view, t_vec2 pixel, float block ,t_vec3 col)
{
	float	x;
	float	y;
	float	temp;

	temp = pixel.x;
	y = pixel.y + block;
	if (y > HEIGHT)
		y = HEIGHT;
	x = pixel.x + block;
	if (x > WIDTH)
		x = WIDTH;
	while (pixel.y < y)
	{
		pixel.x = temp;
		while (pixel.x < x)
		{
			write_pixel(view, pixel, col);
			pixel.x += 1;
		}
		pixel.y += 1;
	}
}

t_vec2	get_min_t(t_vec2 *it, int count)
{
	t_vec2	min;
	int		i;

	min.x = __INT_MAX__;
	i = 0;
	while (i < count)
	{
		if (it[i].x >= 0 && it[i].x < min.x)
		{
			min.x = it[i].x;
			min.y = i;
		}
		i += 1;
	}
	if (min.x == __INT_MAX__)
	{
		min.x = -1;
	}
	return (min);
}

t_vec2	hit_sphere(t_ray ray, t_sphere *spheres, int count)
{
	t_vec2	*it;
	t_vec2	t;
	int		i;

	it = (t_vec2 *)malloc(count * sizeof(t_vec2));
	if (it == NULL)
		exit(1);
	i = 0;
	while (i < count)
	{
		it[i] = draw_sphere(ray, spheres[i].location, spheres[i].radius);
		i += 1;
	}
	t = get_min_t(it, count);
	free(it);
	return (t);
}

t_bool	is_path_free(t_scene scene, t_ray ray, t_vec3 light)
{
	t_vec2	it;
	t_vec3	at;
	float	t;

	it = hit_sphere(ray, scene.spheres, scene.count.sphere);
	at = vec3_div(vec3_sub(light, ray.origin), ray.direction);
	t = at.y;
	// t = vec3_len(at);
	if (it.x < 0.0 || it.x > t)
	{
		return (TRUE);
	}
	else 
	{
		return (FALSE);
	}
}

t_vec3	ray_trace(t_scene scene, t_ray ray)
{
	t_vec2	it;

	it = hit_sphere(ray, scene.spheres, scene.count.sphere);

	if (it.x < 0.0)
	{
		return (vec3_newv(0.0));
	}
	else
	{
		t_vec3	allcolor;
		int		i;

		i = 0;
		while (i < scene.count.light)
		{
			t_vec3	direction;
			t_vec3	normal;
			t_ray	newray;
	
			newray.origin = at(ray, it.x);
			direction = vec3_norm(vec3_sub(scene.lights[i].location, newray.origin));
			newray.direction = direction;
			normal = vec3_norm(vec3_add(vec3_sub(ray.origin, scene.spheres[(int)it.y].location), vec3_mulv(ray.direction, it.x)));

			if (is_path_free(scene, newray, scene.lights[i].location) == FALSE)
			{	
				i += 1;
				continue ;
			}

			t_vec3	diffuse;
			t_vec3	color;
	
			diffuse = vec3_mapv(vec3_mulv(scene.lights[i].color, vec3_dot(direction, normal)), 0.0, maxf);
			color = vec3_mulv(vec3_mul(scene.spheres[(int)it.y].color, diffuse), scene.lights[i].intensity);
			allcolor = vec3_add(allcolor, color);

			i += 1;

		}

		allcolor = vec3_mapv(allcolor, 1.0, minf);

		return (allcolor);
	}
}

void	_draw(t_scene scene)
{
	t_ray	ray;
	t_vec3	color;
	t_vec2	pixel;

	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while  (pixel.x < WIDTH)
		{
			ray = get_ray(pixel, scene.camera, scene.matrix);
			color = ray_trace(scene, ray);
			__draw(scene.view, pixel, scene.block, color);
			pixel.x += scene.block;
		}
		pixel.y += scene.block;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}

#define LOL	1.5

void	draw_smooth(t_scene scene)
{
	t_ray	ray[5];
	t_vec3	color[5];
	t_vec2	pixel;

	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while  (pixel.x < WIDTH)
		{
			ray[0] = get_ray(vec2_new(pixel.x - LOL, pixel.y - LOL), scene.camera, scene.matrix);
			ray[1] = get_ray(vec2_new(pixel.x - LOL, pixel.y + LOL), scene.camera, scene.matrix);
			ray[2] = get_ray(vec2_new(pixel.x + LOL, pixel.y - LOL), scene.camera, scene.matrix);
			ray[3] = get_ray(vec2_new(pixel.x + LOL, pixel.y + LOL), scene.camera, scene.matrix);
			ray[4] = get_ray(vec2_new(pixel.x, pixel.y), scene.camera, scene.matrix);
			color[0] = ray_trace(scene, ray[0]);
			color[1] = ray_trace(scene, ray[1]);
			color[2] = ray_trace(scene, ray[2]);
			color[3] = ray_trace(scene, ray[3]);
			color[4] = ray_trace(scene, ray[4]);
			// color[0] = vec3_divv(vec3_add(vec3_add(vec3_add(color[0], color[1]), color[2]), color[3]), 4);
			color[0] = vec3_divv(vec3_add(vec3_add(vec3_add(vec3_add(color[0], color[1]), color[2]), color[3]), color[4]), 5);
			__draw(scene.view, pixel, scene.block, color[0]);
			pixel.x += scene.block;
		}
		pixel.y += scene.block;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}

void	draw(t_scene scene)
{
	if (scene.smooth == TRUE)
	{
		draw_smooth(scene);
	}
	else
	{
		_draw(scene);
	}
}
