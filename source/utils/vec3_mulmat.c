/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mulmat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:32:03 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 07:21:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec3_mulmat(t_vec3 vec, t_mat matrix)
{
	t_vec3	new;

	new.x = matrix[0][0] * vec.x + matrix[0][1] * vec.y + matrix[0][2] * vec.z;
	new.y = matrix[1][0] * vec.x + matrix[1][1] * vec.y + matrix[1][2] * vec.z;
	new.z = matrix[2][0] * vec.x + matrix[2][1] * vec.y + matrix[2][2] * vec.z;
	return (new);
}

t_vec3	vec3_mulmat_xy(t_vec3 vec, t_mat matrix)
{
	t_vec3	new;

	new.x = matrix[0][0] * vec.x + matrix[0][1] * vec.y;
	new.y = matrix[1][0] * vec.x + matrix[1][1] * vec.y;
	new.z = vec.z;
	return (new);
}
