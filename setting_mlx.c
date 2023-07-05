/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/05 18:28:15 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_mlx(t_vars *vars, t_image *image)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_perror("ERROR: Invalid mlx init");
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	image->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	image->ptr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
		&image->line_length, &image->endian);
}

void	print_mlx(t_vars *vars, t_image *image)
{
	mlx_put_image_to_window(vars->mlx, vars->win, image->img, 150, 150);
	mlx_hook(vars->win, 02, 1L << 0, quit_window, vars);
	mlx_loop(vars->mlx);
}

int	quit_window(int ket_code, t_vars *vars)
{
	if (ket_code == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	pixel_input_color(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->ptr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
