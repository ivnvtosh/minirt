/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:46 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:15:12 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_pixel(t_view view, t_vec2 pixel, t_vec3 col)
{
	unsigned char	*buffer;
	int				_pixel;

	if (pixel.x < 0.0 || pixel.x > WIDTH || pixel.y < 0.0 || pixel.y > HEIGHT)
	{
		printf("\x1b[41m\x1b[1m 💥 BOOM 💥 \x1b[0m\n");
		vec2_print("pixel", pixel);
		exit(1);
	}
	buffer = (unsigned char *)view.buffer;
	_pixel = (pixel.y * view.line) + (pixel.x * 4);
	buffer[_pixel + 0] = col.z * 255;
	buffer[_pixel + 1] = col.y * 255;
	buffer[_pixel + 2] = col.x * 255;
}
