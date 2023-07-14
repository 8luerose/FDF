/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:49:45 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/14 10:51:57 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_center(t_map *map)
{
	int	i;
	int	size;

	i = 0;
	size = map->height * map->width;

	while (i < size)
	{
		map->p_map[i].x += WIDTH / 2;
		map->p_map[i].y += HEIGHT / 2;
		i++;
	}
}