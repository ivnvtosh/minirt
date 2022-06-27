/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:31:36 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:11:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	matrix_rotate(t_mat matrix, t_vec3 angle)
{
	matrix_rotate_z(matrix, angle.z);
	matrix_rotate_x(matrix, angle.x);
	matrix_rotate_y(matrix, angle.y);
}
