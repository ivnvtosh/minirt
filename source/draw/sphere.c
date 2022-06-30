/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:44 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/30 04:57:13 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec2	draw_sphere(t_ray ray, t_vec3 center, float radius)
{
	t_vec3	origin;
	float	b;
	float	c;
	float	h;

	origin = vec3_sub(ray.origin, center);
	b = vec3_dot(origin, ray.direction);
	c = vec3_dot(origin, origin) - radius * radius;
	h = b * b - c;
	if (h < 0.0)
	{
		return (vec2_new(-1.0, -1.0));
	}
	else
	{
		h = sqrt(h);
		return (vec2_new(-b - h, -b + h));
	}
}

// t_vec2	draw_sphere(t_ray ray, t_vec3 center, float radius)
// {
// 	t_vec3	origin;
// 	float	a;
// 	float	b;
// 	float	c;
// 	float	d;

// 	origin = vec3_sub(ray.origin, center);

// 	a = vec3_dot(ray.direction, ray.direction);
// 	b = vec3_dot(origin, ray.direction) * 2.0;
// 	c = vec3_dot(origin, origin) - radius * radius;
// 	d = b * b - 4 * a * c;
// 	if (d < 0.0)
// 	{
// 		return (vec2_new(-1.0, -1.0));
// 	}
// 	else
// 	{
// 		d = sqrt(d);
// 		return (vec2_new((-b - d) / (2.0 * a), -b + d));
// 	}
// }
