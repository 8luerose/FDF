/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:36:10 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/28 15:17:33 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	memory_leaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	atexit(memory_leaks);

	t_map	map;
	t_vars	vars;
	t_image	image;

	if (ac == 2)
	{
		if (!is_valid_file(av[1]))
			ft_perror("ERROR: Invalid file name");
		parsing(av[1], &map);
		isometric(&map);
		max_min_xy(&map);
		image_size_up(&map);
		set_mlx(&vars, &image);
		draw_col(&image, &map);
		draw_row(&image, &map);
		print_mlx(&vars, &image);
	}
	return (0);
}
