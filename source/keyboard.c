/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:11:18 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "key.h"

t_bool	ismovement(int key, t_scene *scene)
{
	t_vec3	vector;

	if (key == KEY_W)
		vector = vec3_new(1.0, 0.0, 0.0);
	else if (key == KEY_A)
		vector = vec3_new(0.0, -1.0, 0.0);
	else if (key == KEY_S)
		vector = vec3_new(-1.0, 0.0, 0.0);
	else if (key == KEY_D)
		vector = vec3_new(0.0, 1.0, 0.0);
	else if (key == KEY_SPASE)
		vector = vec3_new(0.0, 0.0, -1.0);
	else if (key == KEY_Z)
		vector = vec3_new(0.0, 0.0, 1.0);
	else
		return (FALSE);
	vector = vec3_mulmat_xy(vector, scene->matrix);
	vector = vec3_add(scene->camera.location, vec3_mulv(vector, 50.0));
	scene->camera.location = vector;
	return (TRUE);
}

int	key_pressed(int key, t_scene *scene)
{
	if (ismovement(key, scene) == TRUE)
	{
		draw(*scene);
		return (0);
	}
	else if (key == KEY_ESC)
	{
		terminate(scene);
	}
	else
	{
		printf("key: %d\n", key);
		return (0);
	}
	draw(*scene);
	return (0);
}
