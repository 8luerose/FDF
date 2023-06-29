/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:50:44 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/29 13:37:41 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int main()
{
	void *mlx;
	mlx = mlx_init();
	void *win;
	win = mlx_new_window(mlx, 1000, 1000, "test");
	void	*image = mlx_new_image(mlx, 500, 500);
	int		bit_per_pixel1 = 0;
	int		size_line1 = 0;
	int		endian1 = 0;
	char	*ptr = mlx_get_data_addr(image, &bit_per_pixel1, &size_line1, &endian1);

	for (int i = 0; i < 200; i++)
	{
		for(int k = 0; k < 200; k++)
		{
			char *dst2;
			dst2 = ptr + (k * size_line1 + i * bit_per_pixel1 / 8);
			*(unsigned int *)dst2 = create_argb(0, 0, 255, 0);
		}
	}

	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(mlx);
	
	return 0;
}
