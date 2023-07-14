/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_xy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:14:03 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/15 00:16:38 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	max_min_xy(t_map *map)
{
	map->max_x = find_max_x(map);
	map->max_y = find_max_y(map);
	map->min_x = find_min_x(map);
	map->min_y = find_min_y(map);

	printf("\nmax_min_xy: %f %f \n %f %f\n", map->max_x, map->max_y, map->min_x, map->min_y);
}

double	find_max_x(t_map *map)
{
	double	max;
	int		i;

	max = -999999999;
	i = 0;
	while(i < map->width * map->height)
	{
		if (map->p_map[i].x > max)
		{
			max = map->p_map[i].x;
		}
		i++;
	}
	return (max);
}

double	find_max_y(t_map *map)
{
	double	max;
	int		i;

	max = -999999999;
	i = 0;
	while(i < map->width * map->height)
	{
		if (map->p_map[i].y > max)
		{
			max = map->p_map[i].y;
		}
		i++;
	}
	return (max);
}

double	find_min_x(t_map *map)
{
	double	min;
	int		i;

	min = 999999999;
	i = 0;
	while(i < map->width * map->height)
	{
		if (map->p_map[i].x < min)
		{
			min = map->p_map[i].x;
		}
		i++;
	}
	return (min);
}

double	find_min_y(t_map *map)
{
	double	min;
	int		i;

	min = 999999999;
	i = 0;
	while(i < map->width * map->height)
	{
		if (map->p_map[i].y < min)
		{
			min = map->p_map[i].y;
		}
		i++;
	}
	return (min);
}