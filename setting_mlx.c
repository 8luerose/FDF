/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/05 20:30:45 by taehkwon         ###   ########.fr       */
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

<<<<<<< HEAD
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
=======
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

void	pixel_input_color(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->ptr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}