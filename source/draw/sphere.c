/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:44 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:15:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_vec2	draw_sphere(t_vec3 ro, t_vec3 rd, float ra)
{
	float	b;
	float	c;
	float	h;

	b = vec3_dot(ro, rd);
	c = vec3_dot(ro, ro) - ra * ra;
	h = b * b - c;
	if (h < 0.0)
	{
		return (vec2_new(-1.0, 0.0));
	}
	else
	{
		h = sqrt(h);
		return (vec2_new(-b - h, -b + h));
	}
}
