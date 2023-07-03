/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 05:54:30 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/03 15:00:09 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	int	i;
	int	map_size;

	map_size = (map->height) * (map->width);
	i = 0;
	while (i < map_size)
	{
		rotate_z(&(map->p_map[i].x), &(map->p_map[i].y), &(map->p_map[i].z));
		rotate_x(&(map->p_map[i].x), &(map->p_map[i].y), &(map->p_map[i].z));
		i++;
	}
}

void	rotate_x(double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;
	double	theta;

	previous_x = 0.0;
	previous_y = *y;
	previous_z = *z;
	theta = M_PI / 3;
	*x = previous_x;
	*y = previous_y * cos(theta) - previous_z * sin(theta);
	*z = previous_y * sin(theta) + previous_z * cos(theta);
}

void	rotate_y(double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;
	double	theta;

	previous_x = *x;
	previous_y = 0.0;
	previous_z = *z;
	theta = M_PI / 6;
	*x = previous_x * cos(theta) + previous_z * sin(theta);
	*y = previous_y;
	*z = previous_x * -1 * sin(theta) + previous_z * cos(theta);
}

void	rotate_z(double *x, double *y, double *z)
{
	double	previous_x;
	double	previous_y;
	double	previous_z;
	double	theta;

	previous_x = *x;
	previous_y = *y;
	previous_z = 0.0;
	theta = M_PI / 4 * -1;
	*x = previous_x * cos(theta) - previous_y * sin(theta);
	*y = previous_x * sin(theta) + previous_y * cos(theta);
	*z = previous_z;
}
