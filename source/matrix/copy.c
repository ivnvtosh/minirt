/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:28:45 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/27 04:24:00 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	matrix_copy(t_mat matrix, t_mat b)
{
	matrix_column(matrix[0], b[0][0], b[0][1], b[0][2]);
	matrix_column(matrix[1], b[1][0], b[1][1], b[1][2]);
	matrix_column(matrix[2], b[2][0], b[2][1], b[2][2]);
}