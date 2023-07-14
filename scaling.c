/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:04:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/15 01:40:08 by taehkwon         ###   ########.fr       */
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
	
	// gap = (HEIGHT / (double)map->height) * 0.4;
	// gap = 10;
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
	printf("first gap= %f\n", gap);
	
	
	// //type(1)

	// while (gap > 1)
	// {
	// 	// if ((100 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) && 
	// 	// 	(100 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100)){
	// 	// 	printf("break gap= %f\n", gap);
	// 	// 	break;
	// 	// }
	// 	if (((WIDTH - map->width) / 2 < fabs(map->min_x * gap)) && (fabs(map->min_x * gap) < WIDTH - (WIDTH - map->width) / 2) \
	// 		&& ((WIDTH - map->width) / 2  < fabs(map->max_x * gap)) && (fabs(map->max_x * gap) < WIDTH - (WIDTH - map->width) / 2) \
	// 		&& ((HEIGHT - map->height) / 2  < fabs(map->min_y * gap)) && (fabs(map->min_y * gap) < HEIGHT - (HEIGHT - map->height) / 2) \
	// 		&& ((HEIGHT - map->height) / 2 < fabs(map->max_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - (HEIGHT - map->height) / 2))
	// 		{
	// 		printf("break gap= %f\n", gap);
	// 		break;
	// 		}
	// 	gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	// }

	// if (gap <= 1)
	// 	gap = 1; // 1보다 큰 최소한의 gap



	// //type(2)

	// while (gap > 1)
	// {
	// 	// if ((100 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) && 
	// 	// 	(100 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100)){
	// 	// 	printf("break gap= %f\n", gap);
	// 	// 	break;
	// 	// }
	
	// 	if ((map->max_x * gap < WIDTH - (WIDTH - (map->width)) / 2.0) \
	// 		&& (map->max_y * gap < HEIGHT - (HEIGHT - (map->height)) / 2.0))
	// 		{
	// 			printf("break gap= %f\n", gap);
	// 			break;
	// 		}
	// 	gap -= 0.1;
	
	// 	// 	if ((map->width * gap > WIDTH) || (map->height * gap > HEIGHT))
	// 	// {
	// 	// 	if ((map->width * gap < WIDTH - (WIDTH - (map->width)) / 2.0) \
	// 	// 		&& (map->height * gap < HEIGHT - (HEIGHT - (map->height)) / 2.0))
	// 	// 		{
	// 	// 			printf("break gap= %f\n", gap);
	// 	// 			break;
	// 	// 		}
	// 	// 	gap -= 0.1;
	// 	// }
	// }


	// type(3)

	// gap = 100;
	// while (gap > 1)
	// {
	// 	// if ((100 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) && 
	// 	// 	(100 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100)){
	// 	// 	printf("break gap= %f\n", gap);
	// 	// 	break;
	// 	// }
	// 	if ((map->width * gap > WIDTH) || (map->height * gap > HEIGHT))
	// 	{
	// 		// if ((200 < fabs(map->min_x * gap)) && (fabs(map->min_x * gap) < WIDTH - 200) \
	// 		// 	&& (200  < fabs(map->max_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 200) \
	// 		// 	&& (200  < fabs(map->min_y * gap)) && (fabs(map->min_y * gap) < HEIGHT - 200) \
	// 		// 	&& (200 < fabs(map->max_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 200))
	// 		// // if ((fabs(map->min_x * gap) < WIDTH - 200) \
	// 		// // 	&&(fabs(map->max_x * gap) < WIDTH - 200) \
	// 		// // 	&&(fabs(map->min_y * gap) < HEIGHT - 200) \
	// 		// // 	&&(fabs(map->max_y * gap) < HEIGHT - 200))
	// 		// {
	// 		// 	printf("break gap= %f\n", gap);
	// 		// 	break;
	// 		// }
	// 		printf("*\n");
	// 		break;
	// 	}
	// 	gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	// 	// gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	// }

	// if (gap <= 1)
	// 	gap = 1; // 1보다 큰 최소한의 gap



	gap = 100;
	while (gap > 1)
	{
		// if ((100 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 100) && 
		// 	(100 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 100)){
		// 	printf("break gap= %f\n", gap);
		// 	break;
		// }
		// if ((map->width * gap < WIDTH) && (map->height * gap < HEIGHT))
		// {
		// 	// if ((200 < fabs(map->min_x * gap)) && (fabs(map->min_x * gap) < WIDTH - 200) \
		// 	// 	&& (200  < fabs(map->max_x * gap)) && (fabs(map->max_x * gap) < WIDTH - 200) \
		// 	// 	&& (200  < fabs(map->min_y * gap)) && (fabs(map->min_y * gap) < HEIGHT - 200) \
		// 	// 	&& (200 < fabs(map->max_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - 200))
		// 	// // if ((fabs(map->min_x * gap) < WIDTH - 200) \
		// 	// // 	&&(fabs(map->max_x * gap) < WIDTH - 200) \
		// 	// // 	&&(fabs(map->min_y * gap) < HEIGHT - 200) \
		// 	// // 	&&(fabs(map->max_y * gap) < HEIGHT - 200))
		// 	// {
		// 	// 	printf("break gap= %f\n", gap);
		// 	// 	break;
		// 	// }
		// 	printf("**********\n");
		// 	break;
		// }
		// if (((WIDTH - map->width) / 2 < fabs(map->min_x * gap)) && (fabs(map->min_x * gap) < WIDTH - (WIDTH - map->width) / 2) \
		// 	&& ((WIDTH - map->width) / 2  < fabs(map->max_x * gap)) && (fabs(map->max_x * gap) < WIDTH - (WIDTH - map->width) / 2) \
		// 	&& ((HEIGHT - map->height) / 2  < fabs(map->min_y * gap)) && (fabs(map->min_y * gap) < HEIGHT - (HEIGHT - map->height) / 2) \
		// 	&& ((HEIGHT - map->height) / 2 < fabs(map->max_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - (HEIGHT - map->height) / 2 ))
			// if ((fabs(map->min_x * gap) < WIDTH - 200) \
			// 	&&(fabs(map->max_x * gap) < WIDTH - 200) \
			// 	&&(fabs(map->min_y * gap) < HEIGHT - 200) \
			// 	&&(fabs(map->max_y * gap) < HEIGHT - 200))
		if ((750 < fabs(map->min_x * gap)) && (fabs(map->max_x * gap) < WIDTH - (WIDTH - map->width) / 2) \
			&& (750 < fabs(map->min_y * gap)) && (fabs(map->max_y * gap) < HEIGHT - (HEIGHT - map->height) / 2 ))
			{
				printf("break gap= %f\n", gap);
				break;
			}
		gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
		// gap -= 0.1; // gap 감소 폭 조정이 필요할 수 있음
	}

	if (gap <= 1)
		gap = 1; // 1보다 큰 최소한의 gap

	// if (gap <= 1)
	// 	gap = 1; // 1보다 큰 최소한의 gap

	// //type(1)

	// printf("WIDTH: %d   HEIGHT: %d\n", WIDTH, HEIGHT);
	// printf("(WIDTH - map->width) / 2 = %f\n", (WIDTH - map->width) / 2.0 );
	// printf("|| fabs(map->min_x * gap)= %f\n", fabs(map->min_x * gap));
	// printf("WIDTH - (WIDTH - map->width) / 2= %f\n", WIDTH - (WIDTH - map->width) / 2.0);
	// printf("|| fabs(map->max_x * gap)= %f\n", fabs(map->max_x * gap));
	// printf("(HEIGHT - map->height) / 2 = %f\n", (HEIGHT - map->height) / 2.0 );
	// printf("|| fabs(map->min_y * gap)= %f\n", fabs(map->min_y * gap));
	// printf("HEIGHT - (HEIGHT - map->height) / 2= %f\n", HEIGHT - (HEIGHT - map->height) / 2.0);
	// printf("|| fabs(map->max_y * gap)= %f\n", fabs(map->max_y * gap));

	// printf("WIDTH: %d   HEIGHT: %d\n", WIDTH, HEIGHT);
	// printf("WIDTH - (WIDTH - (map->width)) / 2) = %f\n", (WIDTH - (WIDTH - (map->width)) / 2.0));
	// printf("HEIGHT - (HEIGHT - (map->height)) / 2)= %f\n", (HEIGHT - (HEIGHT - (map->height)) / 2.0));
	// printf("|| (map->width * gap)= %f\n", (map->width * gap));
	// printf("|| (map->height * gap)= %f\n", (map->height * gap));

	//type(3)
	// printf("WIDTH: %d   HEIGHT: %d\n", WIDTH, HEIGHT);
	// printf("(WIDTH - 200) = %d\n", (WIDTH - 200));
	// printf("map->width * gap = %f\n", map->width * gap);
	// printf("(HEIGHT - 200) = %d\n", (HEIGHT - 200));
	// printf("map->height * gap = %f\n", map->height * gap);
	
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