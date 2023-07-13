/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:36:10 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/14 01:38:41 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_vars	vars;
	t_image	image;
	// int		line_length = 0;
	// int		bit_per_pixel1 = 0;

	if (ac == 2)
	{
		if (!is_valid_file(av[1]))
			ft_perror("ERROR: Invalid file name");
		parsing(av[1], &map);
		

		isometric(&map);

		
		//등각투영법 이후 x,y,z 출력
		int i = 0;
		while (i < map.width * map.height)
		{
			printf("(%f,%f,%f), %d|| ",map.p_map[i].x, map.p_map[i].y, map.p_map[i].z, map.p_map[i].color);
			i++;
		}
	
		max_min_xy(&map);

		image_size_up(&map);

		set_mlx(&vars, &image);		
		printf("draw In\n");
		// draw_img(&image, &map);
		draw_col(&image, &map);
		draw_row(&image, &map);
		printf("draw Out\n");
		// //draw

		// for (int i =0 ; i< 200  ; i++)
		// {
		// 	for(int k = 0; k<200; k++)
		// 	{
		// 		char *dst2;
		// 		// 8 = sizeof(char)
		// 		dst2 = image.ptr + (k * size_line1 + i * bit_per_pixel1 / 8 );
		// 		*(unsigned int*)dst2 = map.p_map[k + i].color;
		// 	}
		// }

		// for (int i =0 ; i< 200  ; i++)
		// {
		// 	for(int k = 0; k<200; k++)
		// 	{
		// 		char *dst2;
		// 		// 8 = sizeof(char)
		// 		dst2 = image.ptr + (k * image.line_length + i * image.bits_per_pixel / 8 );
		// 		*(unsigned int*)dst2 = 16777215;
		// 	}
		// }

		print_mlx(&vars, &image);

	}
	return (0);
}

