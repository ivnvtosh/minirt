/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:26:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/01 01:28:33 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_mapv(t_vec3 vec, float value, float (*func)(float, float))
{
	vec.x = func(vec.x, value);
	vec.y = func(vec.y, value);
	vec.z = func(vec.z, value);
	return (vec);
}

t_vec3	vec3_map(t_vec3 a, t_vec3 b, float (*func)(float, float))
{
	a.x = func(a.x, b.x);
	a.y = func(a.y, b.y);
	a.z = func(a.z, b.z);
	return (a);
}
