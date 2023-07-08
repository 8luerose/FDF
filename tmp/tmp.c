/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:06:36 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/07 19:06:33 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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





// Algorithm DDA(x1, y1, x2, y2)
//  {
//     dx = x2 - x1
//     dy = y2 - y1
//     // dx는 x좌표의 차이, dy는 y좌표의 차이
    
//     if (abs(dx) > abs(dy))
//     	step = abs(dx)
//     else
//     	step = abs(dy)
//     // dx > dy : 기울기가 1보다 작을경우
//     // dx < dy : 기울기가 1보다 클 경우
    
//     xinc = dx / step
//     yinc = dy / step
//     while (i <= step)
//     {
//     	put_pixel()
//         x = x + xinc
//         y = y + yinc
//     }
//  }

// void	dda(t_image *img, t_map *map, t_coord first, t_coord second)
// {
// 	t_line	line_info;
// 	int		i;

// 	line_info.dx = second.x - first.x;
// 	line_info.dy = second.y - first.y;
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
// 		if (is_over_window(map, first))
// 			continue ;
// 		put_pixel(img, first.x + TEST, \
// 			first.y + TEST, first.color);
// 		first.x = first.x + line_info.xinc;
// 		first.y = first.y + line_info.yinc;
// 	}
// }




// void	draw_img(t_image *image, t_map *map)
// {
// 	double	x;
// 	double	y;
// 	int		color;
// 	int		i;
// 	int		size;

// 	//printf("*****\n");

// 	// size = map->width * map->height;
// 	// i = 0;
// 	// while (i < size)
// 	// {
// 	// 	x = map->p_map[i].x;
// 	// 	y = map->p_map[i].y;
// 	// 	color = map->p_map[i].color;
// 	// 	if(!((x + TEST < 0 && y + TEST < 0) || (x + TEST > WIDTH && y + TEST > HEIGHT)))
// 	// 		pixel_input_color(image, x + TEST, y + TEST, color);
// 	// 	i++;
// 	// }

// 	size = map->width * map->height;
// 	i = 0;
// 	while (i < size)
// 	{
// 		x = map->p_map[i].x;
// 		y = map->p_map[i].y;
// 		color = map->p_map[i].color;
// 		if(!((x + TEST < 0 && y + TEST < 0) || (x + TEST > WIDTH && y + TEST > HEIGHT)))
// 			pixel_input_color(image, x + TEST, y + TEST, color);
// 		i++;
// 	}
// }
