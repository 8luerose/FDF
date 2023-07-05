/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:25:51 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/05 20:27:30 by taehkwon         ###   ########.fr       */
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

	size = map->width * map->height;
	i = 0;
	while (i < size)
	{
		x = map->p_map[i].x;
		y = map->p_map[i].y;
		color = map->p_map[i].color;
		pixel_input_color(image, x, y, color);
		i++;
	}
}

void	draw_col(t_image *img, t_map *map)
{
	t_coord	start;
	t_coord	end;
	int		x;
	int		y;

	y = 0;
	while (y < map->width)
	{
		x = 0;
		while (x < map->height - 1)
		{
			start = map->p_map[y + map->width * x];
			end = map->p_map[y + map->width * (x + 1)];
			dda(img, map, start, end);
			x++;
		}
		y++;
	}
}
void	draw_row(t_image *img, t_map *map)
{
	t_coord	start;
	t_coord	end;
	int		x;
	int		y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height - 1)
		{
			start = map->p_map[x + map->width * y];
			end = map->p_map[x + map->width * (y + 1)];
			dda(img, map, start, end);
			y++;
		}
		x++;
	}
}
void	DDA(x1, y1, x2, y2)
 {
    dx = x2 - x1
    dy = y2 - y1
    // dx는 x좌표의 차이, dy는 y좌표의 차이
    
    if (abs(dx) > abs(dy))
    	step = abs(dx)
    else
    	step = abs(dy)
    // dx > dy : 기울기가 1보다 작을경우
    // dx < dy : 기울기가 1보다 클 경우
    
    xinc = dx / step
    yinc = dy / step
    while (i <= step)
    {
    	put_pixel()
        x = x + xinc
        y = y + yinc
    }
 }
 

 // int	is_over_window(t_map *map, t_point point1)
// {
// 	return (point1.x + get_width_center(map) + map->move_x > WIDTH \
// 		|| point1.x + get_width_center(map) + map->move_x < 0 \
// 		|| point1.y + get_height_center(map) + map->move_y > HEIGHT \
// 		|| point1.y + get_height_center(map) + map->move_y < 0);
// }

// void	dda(t_img *data, t_map *map, t_point point1, t_point point2)
// {
// 	t_line	line_info;
// 	int		i;

// 	line_info.dx = point2.x - point1.x;
// 	line_info.dy = point2.y - point1.y;
// 	if (fabs(line_info.dx) > fabs(line_info.dy))
// 		line_info.step = fabs(line_info.dx);
// 	else
// 		line_info.step = fabs(line_info.dy);
// 	if (!line_info.step)
// 		return ;
// 	line_info.xinc = line_info.dx / line_info.step;
// 	line_info.yinc = line_info.dy / line_info.step;
// 	i = -1;
// 	while (++i <= line_info.step)
// 	{
// 		if (is_over_window(map, point1))
// 			continue ;
// 		put_pixel(data, point1.x + get_width_center(map) + map->move_x, \
// 			point1.y + get_height_center(map) + map->move_y, point1.color);
// 		point1.x = point1.x + line_info.xinc;
// 		point1.y = point1.y + line_info.yinc;
// 	}
// }
