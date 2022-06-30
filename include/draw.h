/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:20:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/30 02:32:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minirt.h"

struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
};

typedef struct s_ray	t_ray;

t_vec3	reflect(t_vec3 rd, t_vec3 n);
t_vec2	draw_sphere(t_ray ray, t_vec3 center, float radius);
void	write_pixel(t_view view, t_vec2 pixel, t_vec3 col);

#endif // DRAW_H
