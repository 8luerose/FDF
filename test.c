/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:50:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/28 21:04:28 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx,h"

void	*mlx = mlx_init();
void	*win = mlx_new_window(mlx, 1000, 1000, "test");

int	color = create_trgb(0, 255, 0, 0);
mlx_pixel_put(mlx, win, 200, 300, color);

void	*image = mlx_new_image(mlx, 500, 500);
int		bit_per_pixel1 = 0;
int		size_line1 = 0;
int		endian1 = 0;
char	*ptr = mlx_get_data_addr(image, &bit_per_pixel1, &size_line1, &endian1);

int	create_argb(int a, int r, int g, int b)
{}
