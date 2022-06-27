/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:20:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/26 16:13:39 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "minirt.h"

t_vec3	reflect(t_vec3 rd, t_vec3 n);
t_vec2	draw_sphere(t_vec3 ro, t_vec3 rd, float ra);
void	write_pixel(t_view view, t_vec2 pixel, t_vec3 col);

#endif // DRAW_H
