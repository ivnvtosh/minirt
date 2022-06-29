/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:40 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/29 00:35:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec3	ray_tracing(t_scene scene, t_ray ray, t_bool lol);

float	minf(float a, float b)
{
	if (a < b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

t_vec3	define_color(t_scene scene, t_ray ray, t_sphere sphere, float it)
{
	t_vec3	n;
	t_vec3	reflected;
	t_vec3	color;
	t_vec3	allcolor;
	t_vec3	diffuse;
	t_vec3	specular;

	(void)scene;

	t_light	*lights;
	t_vec3	light;
	int			i;

	lights = scene.lights;
	i = 0;
	allcolor = vec3_newv(0.0);
	while (i < scene.count.light)
	{
		light = vec3_norm(lights[i].location);
		n = vec3_norm(vec3_add(vec3_sub(ray.start, sphere.location), vec3_mulv(ray.direction, it)));

		t_ray newray;

		newray.direction = vec3_new(-light.x,  -light.y, -light.z);
		newray.start = vec3_add(ray.start, vec3_mulv(ray.direction, it - 1));

		color = ray_tracing(scene, newray, TRUE);
		if ((color.x == 0.0 && color.y == 0.0 && color.z == 0.0))
		{
			i += 1;
			continue ;
		}
		float	dot;
	
		dot = vec3_dot(light, n);
		diffuse.x = maxf(0.0, dot * lights[i].color.x);
		diffuse.y = maxf(0.0, dot * lights[i].color.y);
		diffuse.z = maxf(0.0, dot * lights[i].color.z);

		reflected = reflect(vec3_norm(ray.direction), n);

		float	reflect;
		reflect = vec3_dot(reflected, light);
		specular.x = powf(maxf(0.0, reflect * lights[i].color.x), 16.0);
		specular.y = powf(maxf(0.0, reflect * lights[i].color.y), 16.0);
		specular.z = powf(maxf(0.0, reflect * lights[i].color.z), 16.0);

		color = sphere.color;
		color = vec3_mul(color, diffuse);
		color = vec3_add(color, specular);
		color = vec3_mulv(color, lights[i].intensity);
		color = vec3_add(color, vec3_mulv(sphere.color, 0.05));
		allcolor = vec3_add(allcolor, color);
		i += 1;
	}
	
	allcolor.x = minf(allcolor.x, 1.0);
	allcolor.y = minf(allcolor.y, 1.0);
	allcolor.z = minf(allcolor.z, 1.0);
	return (allcolor);
}

t_vec2	get_t(t_vec2 *it, int count)
{
	t_vec2	min;
	int		i;

	min.x = __INT_MAX__;
	i = 0;
	while (i < count)
	{
		if (it[i].x != -1 && it[i].x < min.x)
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

t_vec3	ray_tracing(t_scene scene, t_ray ray, t_bool lol)
{
	t_vec2	*it;
	int		i;

	it = (t_vec2 *)malloc(scene.count.sphere * sizeof(t_vec2));
	if (it == NULL)
	{
		exit(1);
	}
	
	t_sphere	*spheres;

	spheres = scene.spheres;
	i = 0;
	while (i < scene.count.sphere)
	{
		it[i] = draw_sphere(vec3_sub(ray.start, spheres[i].location), ray.direction, spheres[i].radius);
		i += 1;
	}

	t_vec2	t;

	t = get_t(it, scene.count.sphere);

	if (t.x < 0.0)
	{
		return (vec3_new(0.0, 0.0, 0.0));
	}
	else
	{
		if (lol == TRUE)
			return (vec3_newv(1.0));
		else
			return (define_color(scene, ray, spheres[(int)t.y], t.x));
	}
}

void	_draw(t_view view, t_vec2 pixel, float block ,t_vec3 col)
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

t_ray	get_ray(t_vec2 pixel, t_cam camera, t_mat matrix)
{
	t_ray	ray;
	t_vec3	direction;

	direction = vec3_new(camera.focus, pixel.x - WIDTH / 2.0, pixel.y - HEIGHT / 2.0);
	ray.direction = vec3_norm(direction);
	ray.direction = vec3_mulmat(ray.direction, matrix);
	ray.start = camera.location;
	return (ray);
}

void	draw(t_scene scene)
{
	t_ray	ray;
	t_vec2	pixel;
	t_vec3	col;

	pixel.y = 0.0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0.0;
		while (pixel.x < WIDTH)
		{
			ray = get_ray(pixel, scene.camera, scene.matrix);
			col = ray_tracing(scene, ray, FALSE);
			_draw(scene.view, pixel, scene.block, col);
			pixel.x += scene.block;
		}
		pixel.y += scene.block;
	}
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.canvas, 0, 0);
}

// build
// find
// identify
// compute hit point
// color
