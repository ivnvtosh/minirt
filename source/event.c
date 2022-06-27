/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 06:40:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	event(t_scene *scene)
{
	t_mlx	mlx;

	mlx = scene->mlx;
	mlx_hook(mlx.win, 2, 0, key_pressed, scene);
	mlx_hook(mlx.win, 4, 0, mouse_pressed, scene);
	mlx_hook(mlx.win, 5, 0, mouse_released, scene);
	mlx_hook(mlx.win, 17, 0, terminate, scene);
	mlx_loop(mlx.mlx);
}
