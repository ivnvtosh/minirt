/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:42:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/26 16:41:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

void	vec2_print(char *name, t_vec2 vector)
{
	printf("\x1b[47m\x1b[1m%14s ", name);
	printf("\x1b[0m \x1b[41m \x1b[1m");
	printf("x: %10.2f ", vector.x);
	printf("\x1b[0m \x1b[42m \x1b[1m");
	printf("y: %10.2f ", vector.y);
	printf("\x1b[0m\n");
}
