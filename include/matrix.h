/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:16:30 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 10:16:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include <math.h>

typedef float	t_col[3];
typedef t_col	t_mat[3];

void	matrix_column(t_col column, float a1, float a2, float a3);
void	matrix_copy(t_mat matrix, t_mat b);
void	matrix_multiply(t_mat matrix, t_mat b);
void	matrix_new(t_mat matrix);
void	matrix_print(t_mat matrix);
void	matrix_rotate_x(t_mat matrix, float angle);
void	matrix_rotate_y(t_mat matrix, float angle);
void	matrix_rotate_z(t_mat matrix, float angle);

#endif // MATRIX_H
