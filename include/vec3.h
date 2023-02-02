/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:09 by ccamie            #+#    #+#             */
/*   Updated: 2022/07/01 01:28:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <stdio.h>
# include <math.h>

struct s_vec3
{
	float	x;
	float	y;
	float	z;
};

typedef struct s_vec3	t_vec3;

t_vec3	vec3_addv(t_vec3 vec, float value);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_divv(t_vec3 vec, float value);
t_vec3	vec3_div(t_vec3 a, t_vec3 b);
float	vec3_dot(t_vec3 a, t_vec3 b);
float	vec3_len(t_vec3 vec);
t_vec3	vec3_mapv(t_vec3 vec, float value, float (*func)(float, float));
t_vec3	vec3_map(t_vec3 a, t_vec3 b, float (*func)(float, float));
t_vec3	vec3_mulv(t_vec3 vec, float value);
t_vec3	vec3_mul(t_vec3 a, t_vec3 b);
t_vec3	vec3_newv(float value);
t_vec3	vec3_new(float x, float y, float z);
t_vec3	vec3_norm(t_vec3 vec);
void	vec3_print(char *name, t_vec3 vector);
t_vec3	vec3_subv(t_vec3 a, float value);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);

#endif // VEC3_H
