/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/29 13:52:31 by ccamie           ###   ########.fr       */
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
	draw(*scene);
	return (TRUE);
}

t_bool	isblock(int key, t_scene *scene)
{
	if (key == KEY_PLUS)
	{
		if (scene->block != 1)
			scene->block /= 2;
	}
	else if (key == KEY_MINUS)
	{
		if (scene->block != 128)
			scene->block *= 2;
	}
	else if (key == KEY_ONE)
		scene->block = 1;
	else if (key == KEY_TWO)
		scene->block = 2;
	else if (key == KEY_THREE)
		scene->block = 4;
	else if (key == KEY_FOUR)
		scene->block = 8;
	else if (key == KEY_FIVE)
		scene->block = 16;
	else
		return (FALSE);
	draw(*scene);
	return (TRUE);
}

int	key_pressed(int key, t_scene *scene)
{
	if (ismovement(key, scene) == TRUE)
	{
		return (0);
	}
	else if (isblock(key, scene) == TRUE)
	{
		return (0);
	}
	else if (key == KEY_ESC)
	{
		terminate(scene);
	}
	else
	{
		printf("key: %d\n", key);
	}
	return (0);
}
