/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:21:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/26 16:42:19 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include <stdio.h>

struct s_vec2
{
	float	x;
	float	y;
};

typedef struct s_vec2	t_vec2;

t_vec2	vec2_new(float x, float y);
void	vec2_print(char *name, t_vec2 vector);

#endif // VEC2_H
