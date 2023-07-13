/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:04:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/14 02:04:32 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_size_up(t_map *map)
{
	int		x;
	int		y;
	double	gap;

	gap = max_gap(map);
	printf("\n\n\n gap: %f \n", gap);

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->p_map[y * map->width + x].x *=	gap;
			map->p_map[y * map->width + x].y *=	gap;
			map->p_map[y * map->width + x].z *= gap;

			// map->p_map[y * map->width + x].x *=	(WIDTH / (double)map->width) * 0.4;
			// map->p_map[y * map->width + x].y *= TEST + 10;
			// map->p_map[y * map->width + x].z *= TEST + 50;

			// map->p_map[y * map->width + x].y *= (HEIGHT / (double)map->height) * 0.4;
			// map->p_map[y * map->width + x].z *= (HEIGHT / (double)map->height) * 0.4;
			x++;
		}
		y++;
	}
}

double	max_gap(t_map *map)
{
	double	gap;
	int		max;
	int		i;

	
	i = 20;
	max = 0;
	// gap = 35;
	
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


	// gap = (WIDTH / (double)map->width) * 0.4;
	// while (gap)
	// {
	// 	// if ((map->width * gap > WIDTH) || (map->height * gap > HEIGHT))
	// 	// {
	// 	// 	// if ((100 < map->p_map[0].x * gap) && (map->p_map[map->width].x * gap < WIDTH - 100) \
	// 	// 	// 	&& (100 < map->p_map[0].y * gap) && (map->p_map[map->height * map->width].y * gap < HEIGHT - 100))
	// 	// 	if ((100 < map->width * gap) && (map->width * gap < WIDTH - 100) \
	// 	// 		&& (100 < map->height * gap) && (map->height * gap < HEIGHT - 100))
	// 	// 	{
	// 	// 		printf("break gap\n");
	// 	// 		break;
	// 	// 	}
	// 	// }
	// 	if ((100 < map->width * gap) && (map->width * gap < WIDTH - 100) \
	// 			&& (100 < map->height * gap) && (map->height * gap < HEIGHT - 100))
	// 	{
	// 		printf("break gap\n");
	// 		break;
	// 	}
	// 	gap--;
	// }
	// if (gap == 0)
	// 	gap = 1;
	// return (gap);

	// gap = (WIDTH / (double)map->width) * 0.4;

	// while (gap > 1)
	// {
	// 	if ((100 < map->width * gap) && (map->width * gap < WIDTH - 100) && 
	// 		(100 < map->height * gap) && (map->height * gap < HEIGHT - 100))
	// 	{
	// 		printf("break gap= %f\n", gap);
	// 		break;
	// 	}
	// 	gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	// }

	// if (gap <= 1)
	// 	gap = 1; // 1보다 큰 최소한의 gap

	// return gap;


	gap = (WIDTH / (double)map->width) * 0.4;

	while (gap > 1)
	{
		// if ((100 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) && 
		// 	(100 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100)){
		// 	printf("break gap= %f\n", gap);
		// 	break;
		// }
		if (((WIDTH - map->width) / 2 < fabs(map->min_x * gap)) && (fabs(map->min_x * gap) < WIDTH - 100) \
			&& ((WIDTH - map->width) / 2  < fabs(map->max_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) \
			&& ((HEIGHT - map->height) / 2  < fabs(map->min_y * gap)) && (fabs(map->min_y * gap) < HEIGHT - 100) \
			&& ((HEIGHT - map->height) / 2 < fabs(map->max_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100))
		{
			printf("break gap= %f\n", gap);
			break;
		}
		gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	}

	if (gap <= 1)
		gap = 1; // 1보다 큰 최소한의 gap

	return gap;



	// (점의 가로 개수(파싱한 파일 열의 개수)) * gap > Window_Max_X

	// ||

	// (점의 세로 개수(파싱한 파일 행의 개수)) * gap > Window_Max_Y

	
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


	// if (((HEIGHT / (double)map->height) * 0.4) <= 1)
	// {
	// 	gap = 1;
	// }
	// if (map->height >= 500)
	// {
	// 	gap = 2.25;
	// }
	// else
	// {
	// 	// gap = (HEIGHT / (double)map->height) * 0.4;
	// 	gap = (HEIGHT / (double)map->height) * 0.4;
	// }

	// return (gap);


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