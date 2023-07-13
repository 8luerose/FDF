/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:26:11 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/13 16:39:56 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_row(t_image *image, t_map *map)
{
	int		i;
	int		j;
	t_coord	first_coord;
	t_coord	second_coord;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			first_coord = map->p_map[i * map->width + j];
			second_coord = map->p_map[i * map->width + (j + 1)];
			DDA(image, map, first_coord, second_coord);
			j++;
		}
		i++;
	}
	printf("draw row OUT\n");
}

void	draw_col(t_image *image, t_map *map)
{
	int		i;
	int		j;
	t_coord	first_coord;
	t_coord	second_coord;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height - 1)
		{
			first_coord = map->p_map[j * map->width + i];
			second_coord = map->p_map[(j + 1) * map->width + i];
			DDA(image, map, first_coord, second_coord);
			j++;
		}
		i++;
	}
	printf("draw col OUT\n");
}

 void	DDA(t_image *image, t_map *map, t_coord first, t_coord second)
{
	t_dda	dda_utils;
	t_dda	*p_dda;
	t_coord	*p;
	// int		i;

	dda_utils.dx = second.x - first.x;
	dda_utils.dy = second.y - first.y;
	if (fabs(dda_utils.dx) > fabs(dda_utils.dy))
		dda_utils.step = fabs(dda_utils.dx);
	else
		dda_utils.step = fabs(dda_utils.dy);
	// if (!dda_utils.step)
	// 	return ;
	dda_utils.x_inc = dda_utils.dx / dda_utils.step;
	dda_utils.y_inc = dda_utils.dy / dda_utils.step;
	p = &first;
	p_dda = &dda_utils;
	// i = 0;
	DDA_inc(image, map, p_dda, p);
}

void	DDA_inc(t_image *image, t_map *map, t_dda *dda, t_coord *p)
{
	double	x_diff;
	double	y_diff;
	int		i;

	// x_diff = ((WIDTH / 2) - (map->width / 2)) / 2.0;
	// y_diff = ((HEIGHT / 2) - (map->height / 2)) / 2.0;

	// x_diff = ((WIDTH / 2) - (map->p_map[(map->width / 2) + (map->width * (map->height / 2))].x)) / 1.0;
	// y_diff = ((HEIGHT / 2) - (map->p_map[(map->width / 2) + (map->width * (map->height / 2))].y)) / 1.0;
	x_diff = WIDTH / 2;
	y_diff = HEIGHT / 2;
	i = 0;
	while (i <= dda->step)
	{
		// if(!((p->x + x_diff < 0 && p->y + y_diff < 0) || (p->x + x_diff > WIDTH && p->y + y_diff > HEIGHT)))
		if((p->x + x_diff > 0 && p->y + y_diff > 0) || (p->x + x_diff < WIDTH && p->y + y_diff < HEIGHT))
		{
			pixel_input_color(image, (p->x + x_diff), (p->y + y_diff), p->color);
			// p->x = p->x + dda->x_inc;
			// p->y = p->y + dda->y_inc;
			// pixel_input_color(image, (p->x + dda->x_inc * i + x_diff), (p->y + dda->y_inc * i + y_diff), p->color);
		}
		p->x = p->x + dda->x_inc;
		p->y = p->y + dda->y_inc;
		i++;
	}
}

void	pixel_input_color(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->ptr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*

원래 코드
void	draw_row(t_image *image, t_map *map)
{
	int		i;
	int		j;
	t_coord	first_coord;
	t_coord	second_coord;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width - 1)
		{
			first_coord = map->p_map[i * map->width + j];
			second_coord = map->p_map[i * map->width + (j + 1)];
			DDA(image, map, first_coord, second_coord);
			j++;
		}
		i++;
	}
	printf("draw row OUT\n");
}

void	draw_col(t_image *image, t_map *map)
{
	int		i;
	int		j;
	t_coord	first_coord;
	t_coord	second_coord;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height - 1)
		{
			first_coord = map->p_map[j * map->width + i];
			second_coord = map->p_map[(j + 1) * map->width + i];
			DDA(image, map, first_coord, second_coord);
			j++;
		}
		i++;
	}
	printf("draw col OUT\n");
}

 void	DDA(t_image *image, t_map *map, t_coord first, t_coord second)
{
	t_dda	dda_utils;
	int		i;

	dda_utils.dx = second.x - first.x;
	dda_utils.dy = second.y - first.y;
	if (fabs(dda_utils.dx) > fabs(dda_utils.dy))
		dda_utils.step = fabs(dda_utils.dx);
	else
		dda_utils.step = fabs(dda_utils.dy);
	if (!dda_utils.step)
		return ;
	dda_utils.x_inc = dda_utils.dx / dda_utils.step;
	dda_utils.y_inc = dda_utils.dy / dda_utils.step;
	i = 0;
	// while (i <= dda_utils.step)
	// {
	// 	if(!((first.x + TEST < 0 && first.y + TEST < 0) || (first.x + TEST > WIDTH && first.y + TEST > HEIGHT)))
	// 	{	
	// 		pixel_input_color(image, first.x + TEST, \
	// 			first.y + TEST, first.color);	
	// 		first.x = first.x + dda_utils.x_inc;
	// 		first.y = first.y + dda_utils.y_inc;
	// 	}
	// 	i++;
	// }
	while (i <= dda_utils.step)
	{
		if(!((first.x + TEST < 0 && first.y + TEST < 0) || (first.x + TEST > WIDTH && first.y + TEST > HEIGHT)))
		{	
			pixel_input_color(image, first.x + TEST, \
				first.y + TEST, first.color);	
			first.x = first.x + dda_utils.x_inc;
			first.y = first.y + dda_utils.y_inc;
		}
		i++;
	}
}


*/