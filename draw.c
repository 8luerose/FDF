/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:26:11 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/06 20:03:29 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_img(t_image *image, t_map *map)
{
	double	x;
	double	y;
	int		color;
	int		i;
	int		size;

	//printf("*****\n");

	size = map->width * map->height;
	i = 0;
	while (i < size)
	{
		x = map->p_map[i].x;
		y = map->p_map[i].y;
		color = map->p_map[i].color;
		if(!((x + TEST < 0 && y + TEST < 0) || (x + TEST > WIDTH && y + TEST > HEIGHT)))
			pixel_input_color(image, x + TEST, y + TEST, color);
		i++;
	}
}

void	pixel_input_color(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->ptr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}