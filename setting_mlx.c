/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 07:17:24 by taehkwon         ###   ########.fr       */
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
	image->ptr = mlx_get_data_addr(image->img, image->bits_per_pixel,image->line_length, image->endian);
}

void	print_mlx(t_vars *vars, t_image *image)
{
	mlx_put_image_to_window(vars->mlx, vars->win, image->img, 0, 0);
	mlx_hook(vars->win, 02, 1L<<0, quit_window, vars);
	mlx_loop(vars->mlx);
}

void	quit_window(int ket_code, t_vars *vars)
{
	if (ket_code == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}