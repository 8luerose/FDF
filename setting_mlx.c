/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/19 19:42:26 by taehkwon         ###   ########.fr       */
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
	mlx_put_image_to_window(vars->mlx, vars->win, image->img, 0, 0);
	// mlx_hook(vars->win, 2, 1L << 0, quit_window, vars);
	// mlx_hook(vars->win, 17, 0, quit_window, vars);
	
	mlx_key_hook(vars->win, key_hook, &vars); 
	mlx_hook(vars->win, 17, 0, exit_hook, 0);

	mlx_loop(vars->mlx);
}

// int	quit_window(int ket_code, t_vars *vars)
// {
// 	if (ket_code == 53)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	return (0);
// }

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int exit_hook()
{
	exit(0);
}

// void	draw_img(t_image *image, t_map *map)
// {
// 	double	x;
// 	double	y;
// 	int		color;
// 	int		i;
// 	int		size;

// 	//printf("*****\n");

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

// void	pixel_input_color(t_image *image, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = image->ptr + (y * image->line_length + x * (image->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }