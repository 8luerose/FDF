/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:37:34 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/12 17:27:31 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parsing(char *file_name, t_map *map)
{
	int	fd;
	int	map_size_value;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	
	set_map_size(fd, map, 0);

	//파싱한 width, height 크기
	printf("width: %d  height: %d\n",map->width, map->height);

	close(fd);	
	map_size_value = (map->height) * (map->width);
	map->p_map = (t_coord *)malloc(sizeof(t_coord) * map_size_value);
	if (!(map->p_map))
		ft_perror("ERROR: Invalid map malloc");
	fd = open(file_name, O_RDONLY);
	
	set_map_coord(fd, map, 0, 0);

	//printf("\n");

	//z 파싱 결과
	// for (int i = 0; i < map->height; i++)
	// {
	// 	for (int j = 0; j < map->width; j++)
	// 	{
	// 		t_coord p;
	// 		p = map->p_map[i * map->width];
	// 		// if(p.x)
	// 		// 	printf("x= %0.1f y= %0.1f z= %0.1f", p.x, p.y, p.z);
	// 		if(p.x)
	// 			printf("z= %f", p.z);
	// 	}
	// 	printf("\n");
	// }

	// for (int i = 0; i < map->height; i++)
	// {
	// 	for (int j = 0; j < map->width; j++)
	// 	{
	// 		t_coord p;
	// 		p = map->p_map[i * map->width];
	// 		// if(p.x)
	// 		// 	printf("x= %0.1f y= %0.1f z= %0.1f", p.x, p.y, p.z);
	// 		if(p.x)
	// 			printf("z= %d c= %d  ||", p.z, p.color);
	// 	}
	// 	printf("\n");
	// }

	// for (int i = 0; i < map->height; i++)
	// {
	// 	for (int j = 0; j < map->width; j++)
	// 	{
	// 		// map->p_map[i * map->width + j];
	// 		printf("(%d,%d,%d)  ", map->p_map[i * map->width + j].x, map->p_map[i * map->width + j].y, map->p_map[i * map->width + j].z);
	// 	}
	// 	printf("\n");
	// }
	



	
	// int i = 0;
	// while (i < map->width * map->height)
	// {
	// 	printf("(%f,%f,%f)  ",map->p_map[i].x, map->p_map[i].y, map->p_map[i].z);
	// 	i++;
	// }

	close(fd);
}

void	set_map_size(int fd, t_map *map, int i)
{
	char	*line;
	char	**arr;
	int		check_width;
	int		max;

	line = get_next_line(fd);
	//map->width = get_width(line);
	map->height = 0;
	max = -2147483648;
	while (line)
	{
		arr = ft_split(line, ' ');
		free(line);
		if (arr == NULL || *arr[0] == '\0')
			ft_perror("ERROR: Invalid map");
		check_width = invalid_color_check(arr, i); //i = 0;
		if (!check_width)
			ft_perror("ERROR: Invalid map color");
		free_for_split(arr);
		
		if (check_width >= max)
			max = check_width;

		// if (check_width != map->width)
		// {
		// 	printf("ch_wi: %d\n", check_width);
		// 	printf("ma_wi: %d\n", map->width);
		// 	ft_perror("ERROR: Invalid map size");
		// }
		map->height += 1;
		map->width = max;
		line = get_next_line(fd);
	}
	free(line);
}

void	set_map_coord(int fd, t_map *map, int x, int y)
{
	char	*line;
	char	**arr;
	int		i;
	t_coord	coord;

	line = get_next_line(fd);
	while (line)
	{
		coord.y = y;
		arr = ft_split(line, ' ');

		//map 파싱한 결과.
		// for (int i = 0; i < map->width; i++)
		// {
		// 	printf("%s ", arr[i]);
		// }
		// printf("\n");

		i = 0;
		while (arr[i] && *arr[i] != '\n')
		{		
			get_map_color(arr[i], &coord);
			coord.x = i;
			map->p_map[y * map->width + i] = coord;
			// printf("%f %f\n", coord.x, map->p_map[y * map->width + i].x);
			i++;
		}
		//printf("%f %f\n", coord.x, map->p_map[y * map->width + i -1].x);

		free_for_split(arr);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
}

void	get_map_color(char *arr, t_coord *coord)
{
	char	**color_split;
	int		check_width;
	int		color_value;
	
	color_split = ft_split(arr, ',');
	if (!color_split || !is_valid_num(color_split[0]))
	{
		free_for_split(color_split);
		ft_perror("ERROR: Invalid map number");
	}	
	coord->z = ft_atoi(color_split[0]);


	//컬러값 출력
	// printf("color: %s  z= %f\n", color_split[1], coord->z);
	// printf("\n");

	check_width = is_color(arr);
	if (check_width == 2)
	{
		color_value = input_color(color_split[1], "0123456789abcdef", 0);
		if (color_value == -1)
			ft_perror("ERROR: Invalid color");
		coord->color = color_value;
	}
	else
		coord->color = input_color("0x00FFFFFF", "0123456789abcdef", 0);

	// check_width = is_color(arr);
	// if (check_width == 2)
	// {
	// 	color_value = input_color(color_split[1], "0123456789abcdef", 0);
	// 	if (color_value == -1)
	// 		ft_perror("ERROR: Invalid color");
	// 	coord->color = color_value;
	// }
	// else
	// 	coord->color = 0x00FFFFFF;

	//printf("color: %d\n", coord->color);
	
	// printf("white: %d \n", input_color("0x00FFFFFF", "0123456789abcdef", 0));
}

int	input_color(char *arr, char *hex, int len)
{
	int	i;
	int	result;

	if (!arr)
		return (-1);
	while (arr[len] && arr[len] != '\n')
		len++;
	if (len % 2 == 1 || len > 10)
		return (-1);
	i = 0;
	if (ft_strncmp(arr, "0x", 2) == 0)
		i += 2;
	else
		return (-1);
	result = 0;
	while (arr[i] && arr[i] != '\n')
	{
		if (hex_indexing(hex, arr[i]) == -1)
			return (-1);
		result = result * 16 + hex_indexing(hex, arr[i]);
		i++;
	}
	return (result);
}