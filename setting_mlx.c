/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/04 18:35:37 by taehkwon         ###   ########.fr       */
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
	image->ptr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

void	print_mlx(t_vars *vars, t_image *image)
{
	mlx_put_image_to_window(vars->mlx, vars->win, image->img, 0, 0);
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

void	draw_img(t_image *image, t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = map->width * map->height;

	x = 0;
	y = 0;
	while (i < size)
	{
		
		map->p_map[i]
		i++;
	}
}

// void	pixel_input_color(t_image *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }