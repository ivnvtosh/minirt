/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/28 18:28:04 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"

# include "bool.h"
# include "matrix.h"
# include "vec2.h"
# include "vec3.h"

// # define WIDTH	1920
// # define HEIGHT	1080

# define WIDTH	1080
# define HEIGHT	720

// # define WIDTH	500
// # define HEIGHT	500

struct s_view
{
	char	*buffer;
	int		pixel;
	int		line;
	int		endian;
};

struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*canvas;
};

struct s_cam
{
	t_vec3	location;
	t_vec3	rotation;
	float	fov;
	float	focus;
};

struct s_light
{
	t_vec3	location;
	t_vec3	color;
	float	intensity;
};

struct s_sphere
{
	t_vec3	location;
	t_vec3	rotation;
	t_vec3	scale;
	t_vec3	color;
	float	radius;
};

struct s_count
{
	int	light;
	int	sphere;
};

struct s_scene
{
	struct s_view	view;
	struct s_mlx	mlx;
	struct s_cam	camera;
	struct s_count	count;
	struct s_light	*lights;
	struct s_sphere	*spheres;
	struct s_vec2	mouse;
	t_mat			matrix;
	int				block;
};

typedef struct s_obj	t_obj;
typedef struct s_view	t_view;
typedef struct s_mlx	t_mlx;
typedef struct s_cam	t_cam;
typedef struct s_sphere	t_sphere;
typedef struct s_light	t_light;
typedef struct s_scene	t_scene;

void	draw(t_scene scene);
void	event(t_scene *scene);
int		key_pressed(int key, t_scene *scene);
void	minirt(char *path);
t_scene	parser(char *path);
int		terminate(t_scene *scene);

void	matrix_rotate(t_mat matrix, t_vec3 angle);
float	maxf(float a, float b);
t_vec3	vec3_mulmat(t_vec3 vec, t_mat matrix);
t_vec3	vec3_mulmat_xy(t_vec3 vec, t_mat matrix);

int		mouse_pressed(int key, int x, int y, t_scene *scene);
int		mouse_released(int key, int x, int y, t_scene *scene);

#endif // MINIRT_H
