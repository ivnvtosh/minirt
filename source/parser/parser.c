/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/29 13:58:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_mlx	set_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Mini Ray Tracer");
	mlx.canvas = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	return (mlx);
}

t_view	set_view(void *canvas)
{
	t_view	view;
	int		pixel;
	int		line;
	int		endian;

	view.buffer = mlx_get_data_addr(canvas, &pixel, &line, &endian);
	view.pixel = pixel;
	view.line = line;
	view.endian = endian;
	return (view);
}

t_sphere	*get_spheres(int count)
{
	t_sphere	*spheres;

	spheres = (t_sphere *)malloc(count * sizeof(t_sphere));
	if (spheres == NULL)
	{
		exit(1);
	}
	spheres[0].location = vec3_new(500.0, 0.0, 0.0);
	spheres[0].rotation = vec3_new(0.0, 0.0, 0.0);
	spheres[0].scale = vec3_new(1.0, 1.0, 1.0);
	spheres[0].color = vec3_newv(1.0);
	// spheres[0].color = vec3_new(0.2, 0.3, 0.75);
	spheres[0].radius = 300.0;

	spheres[1].location = vec3_new(550.0, 500.0, 0.0);
	spheres[1].rotation = vec3_new(0.0, 0.0, 0.0);
	spheres[1].scale = vec3_new(1.0, 1.0, 1.0);
	spheres[1].color = vec3_newv(1.0);
	// spheres[1].color = vec3_new(0.8, 0.1, 0.25);
	spheres[1].radius = 100.0;

	spheres[2].location = vec3_new(600.0, 300.0, -100.0);
	spheres[2].rotation = vec3_new(0.0, 0.0, 0.0);
	spheres[2].scale = vec3_new(1.0, 1.0, 1.0);
	spheres[2].color = vec3_newv(1.0);
	// spheres[2].color = vec3_new(0.3, 0.9, 0.25);
	spheres[2].radius = 200.0;

	spheres[3].location = vec3_new(2000.0, 2000.0, -1000.0);
	spheres[3].rotation = vec3_new(0.0, 0.0, 0.0);
	spheres[3].scale = vec3_new(1.0, 1.0, 1.0);
	spheres[3].color = vec3_newv(1.0);
	// spheres[3].color = vec3_new(0.3, 0.9, 0.25);
	spheres[3].radius = 400.0;

	return (spheres);
}

t_light	*get_lights(int count)
{
	t_light	*lights;

	lights = (t_light *)malloc(count * sizeof(t_light));
	if (lights == NULL)
	{
		exit(1);
	}
	lights[0].location = vec3_new(-600.0, 0.0, -1000.0);
	lights[0].color = vec3_new(0.0, 0.2, 1.0);
	// lights[0].color = vec3_newv(1.0);
	lights[0].intensity = 0.8;
	lights[1].location = vec3_new(-300.0, -1000.0, -500.0);
	lights[1].color = vec3_new(0.4, 0.8, 0.1);
	// lights[1].color = vec3_newv(1.0);
	lights[1].intensity = 0.8;
	lights[2].location = vec3_new(-300.0, 500.0, 500.0);
	lights[2].color = vec3_new(0.9, 0.1, 0.1);
	// lights[2].color = vec3_newv(1.0);
	lights[2].intensity = 0.8;
	return (lights);
}

t_scene	parser(char *path)
{
	t_scene	scene;

	(void)path;
	scene.mlx = set_mlx();
	scene.view = set_view(scene.mlx.canvas);
	scene.camera.location = vec3_new(-500.0, 0.0, 0.0);
	scene.camera.rotation = vec3_new(0.0, 0.0, 0.0);
	vec3_print("camera.lot", scene.camera.location);
	// vec3_print("camera.rot", scene.camera.rotation);
	scene.camera.fov = 60.0;
	scene.camera.focus = WIDTH / 2 / tanf(scene.camera.fov / 2 * M_PI / 180);

	matrix_new(scene.matrix);
	matrix_rotate(scene.matrix, scene.camera.rotation);
	scene.block = 4;

	scene.count.sphere = 4;
	scene.spheres = get_spheres(scene.count.sphere);
	
	scene.count.light = 3;
	scene.lights = get_lights(scene.count.light);
	
	return (scene);
}
