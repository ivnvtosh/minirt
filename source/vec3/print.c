/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:42:42 by ccamie            #+#    #+#             */
/*   Updated: 2022/06/26 16:37:10 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	vec3_print(char *name, t_vec3 vector)
{
	printf("\x1b[47m\x1b[1m%14s ", name);
	printf("\x1b[0m \x1b[41m \x1b[1m");
	printf("x: %10.2f ", vector.x);
	printf("\x1b[0m \x1b[42m \x1b[1m");
	printf("y: %10.2f ", vector.y);
	printf("\x1b[0m \x1b[44m \x1b[1m");
	printf("z: %10.2f ", vector.z);
	printf("\x1b[0m\n");
}
