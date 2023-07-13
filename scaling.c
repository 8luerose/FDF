/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:04:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/13 17:16:23 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_size_up(t_map *map)
{
	int		x;
	int		y;
	int		gap;

	gap = max_gap(map);
	printf("\n\n\n gap: %d \n", gap);

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			// map->p_map[y * map->width + x].x *=	gap;
			// map->p_map[y * map->width + x].y *= gap;
			// map->p_map[x + map->width * y].z *= gap;
			map->p_map[y * map->width + x].x *=	(WIDTH / (double)map->width) * 0.4;
			map->p_map[y * map->width + x].y *= TEST + 10;
			map->p_map[y * map->width + x].z *= TEST + 50;
			// map->p_map[y * map->width + x].y *= (HEIGHT / (double)map->height) * 0.4;
			// map->p_map[y * map->width + x].z *= (HEIGHT / (double)map->height) * 0.4;
			x++;
		}
		y++;
	}
}

int	max_gap(t_map *map)
{
	double	gap;
	int		max;
	int		i;

	
	i = 20;
	max = 0;
	gap = 50;
	// while (gap < map->width * map->height)
	printf("map->width: %d    map->height: %d\n\n", map->width, map->height);
	// while (gap > i)
	// {
	// 	if ((map->width * gap > WIDTH) && (map->height * gap > HEIGHT))
	// 	{
	// 		max = gap;
	// 		//printf("max: %d_%d\n", max, gap);
	// 	}
	// 	if (gap == 20)
	// 		break;
	// 	gap--;
	// }
	// return (max);



	// while ((map->width * gap > WIDTH) || (map->height * gap > HEIGHT))
	// {
	// 	gap--;
	// 	if (gap == 30)
	// 		break;
	// }
	// return (gap);

	// if (map->height >= 500)
	// {
	// 	gap = 0;
	// }
	// else if (map->height > )



	// gap = (HEIGHT / (double)map->height) * 0.4;
	if (((HEIGHT / (double)map->height) * 0.4) <= 1)
	{
		gap = 1;
	}
	if (map->height >= 500)
	{
		gap = 2.25;
	}
	else
	{
		// gap = (HEIGHT / (double)map->height) * 0.4;
		gap = (HEIGHT / (double)map->height) * 0.4;
	}

	return (gap);
}

// (점의 가로 개수(파싱한 파일 열의 개수)) * gap > Window_Max_X

// ||

// (점의 세로 개수(파싱한 파일 행의 개수)) * gap > Window_Max_Y

// while (y < var->map_height)
// {
// 	x = 0;
// 	while (x < var->map_width)
// 	{
// 		(var->offset[y][x]).x = x * var->gap;
// 		(var->offset[y][x]).y = y * var->gap;
// 		(var->offset[y][x]).z = var->map[y][x];
// 		x++;
// 	}
// 	y++;
// }

// void	image_size_up(t_map *map)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			map->r_map[y * map->width + x].x *= map->ratio;
// 			map->r_map[y * map->width + x].y *= map->ratio;
// 			map->r_map[x + map->width * y].z *= map->ratio;
// 			x++;
// 		}
// 		y++;
// 	}
// }