/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:36:49 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 07:17:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mouse.h"

static int	mouse_rotate(int x, int y, t_scene *scene)
{
	scene->camera.rotation.z -= (x - scene->mouse.x) * 0.1;
	scene->camera.rotation.y += (y - scene->mouse.y) * 0.1;
	scene->mouse.x = x;
	scene->mouse.y = y;
	matrix_new(scene->matrix);
	matrix_rotate(scene->matrix, scene->camera.rotation);
	draw(*scene);
	return (0);
}

int	mouse_pressed(int key, int x, int y, t_scene *scene)
{
	scene->mouse.x = x;
	scene->mouse.y = y;
	if (key == MOUSE_CLICK_LEFT)
	{
		mlx_hook(scene->mlx.win, 6, 0, mouse_rotate, scene);
	}
	return (0);
}

int	mouse_released(int key, int x, int y, t_scene *scene)
{
	(void)key;
	(void)x;
	(void)y;
	mlx_hook(scene->mlx.win, 6, 0, NULL, NULL);
	return (0);
}
