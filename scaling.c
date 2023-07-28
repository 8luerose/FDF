/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:04:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/27 19:44:43 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_size_up(t_map *map)
{
	int		x;
	int		y;
	double	gap;

	gap = max_gap(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->p_map[y * map->width + x].x *= gap;
			map->p_map[y * map->width + x].y *= gap;
			x++;
		}
		y++;
	}
}

double	max_gap(t_map *map)
{
	double	gap;
	double	x_diff;
	double	y_diff;
	double	x_margin;
	double	y_margin;

	x_diff = fabs(map->max_x) + fabs(map->min_x);
	y_diff = fabs(map->max_y) + fabs(map->min_y);
	gap = 50;
	while (gap > 1)
	{
		x_margin = (WIDTH - fabs(x_diff * gap)) / 2.0;
		y_margin = (HEIGHT - fabs(y_diff * gap)) / 2.0;
		if ((fabs(x_diff * gap) < WIDTH - x_margin - 400) \
			&& ((fabs(y_diff * gap) < HEIGHT - y_margin - 400)))
		{
			break ;
		}
		else
			gap--;
	}
	if (gap <= 1)
		gap = 1;
	return (gap);
}
