/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:37:34 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 05:52:18 by taehkwon         ###   ########.fr       */
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
	close(fd);
	map_size_value = (map->height) * (map->width);
	map->p_map = (t_coord *)malloc(sizeof(t_coord) * map_size_value);
	if (!(map->p_map))
		ft_perror("ERROR: Invalid map malloc");
	fd = open(file_name, O_RDONLY);
	set_map_coord(fd, map, 0, 0);
	close(fd);
}

void	set_map_size(int fd, t_map *map, int i)
{
	char	*line;
	char	**arr;
	int		check_width;

	line = get_next_line(fd);
	map->width = get_width(line);
	map->height = 0;
	while (line)
	{
		arr = ft_split(line, ' ');
		free(line);
		if (arr == NULL || *arr == '\0')
			ft_perror("ERROR: Invalid map");
		check_width = invalid_color_check(arr, i); //i = 0;
		if (!check_width)
			ft_perror("ERROR: Invalid map color");
		free_for_split(arr);
		if (check_width != map->width)
			ft_perror("ERROR: Invalid map size");
		map->height += 1;
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
		i = 0;
		while (arr[i])
		{
			get_map_color(arr[i], &coord);
			coord.x = i;
			map->p_map[y * map->width + x] = coord;
			i++;
		}
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
	check_width = is_color(arr);
	if (check_width == 3)
	{
		color_value = input_color(color_split[1], "0123456789abcdef", 0);
		if (color_value == -1)
			ft_perror("ERROR: Invalid color");
		coord->color = color_value;
	}
	else
		coord->color = 0x00FFFFFF;
}

int	input_color(char *arr, char *hex, int len)
{
	int	i;
	int	result;

	if (!arr)
		return (-1);
	while (arr[len] && arr[len] != '\n')
		len++;
	if (len % 2 == 1 || len > 8)
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
		result = result * 10 + hex_indexing(hex, arr[i]);
		i++;
	}
	return (result);
}