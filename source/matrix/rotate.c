/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:08:53 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:17:03 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	matrix_rotate_x(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], 1.0, 0.0, 0.0);
	matrix_column(rotate[1], 0.0, +cosf(a), +sinf(a));
	matrix_column(rotate[2], 0.0, -sinf(a), +cosf(a));
	matrix_multiply(matrix, rotate);
}

void	matrix_rotate_y(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], cosf(a), 0.0, -sinf(a));
	matrix_column(rotate[1], 0.0, 1.0, 0.0);
	matrix_column(rotate[2], +sinf(a), 0.0, +cosf(a));
	matrix_multiply(matrix, rotate);
}

void	matrix_rotate_z(t_mat matrix, float angle)
{
	float	a;
	t_mat	rotate;

	a = M_PI / 180 * angle;
	matrix_column(rotate[0], +cosf(a), +sinf(a), 0.0);
	matrix_column(rotate[1], -sinf(a), +cosf(a), 0.0);
	matrix_column(rotate[2], 0.0, 0.0, 1.0);
	matrix_multiply(matrix, rotate);
}
