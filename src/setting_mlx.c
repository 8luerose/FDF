/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 06:58:13 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/27 20:39:54 by taehkwon         ###   ########.fr       */
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
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_hook(vars->win, 17, 0, exit_hook, 0);
	mlx_loop(vars->mlx);
}

int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int	exit_hook(void)
{
	exit(0);
}
