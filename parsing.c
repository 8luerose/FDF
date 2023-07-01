/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:37:34 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/01 20:10:46 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_file(char *file_name)
{
	int		result;
	int		len;
	int		**arr;

	arr = ft_split(file_name, '.');
	if (!file_name)
		ft_perror("split error");
	len = 0;
	while (file_name[len] != 0)
		len++;
	if (len < 3)
		return (0);
	result = 0;
	if (ft_strncmp(file_name[len - 1], "fdf", 4) == 0)
		result = 1;
	free_for_split(file_name);
	return (result);
}

void	parsing(char *file_name, t_map *map)
{
	int	fd;
	int	map_size_value;
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	get_map_size(fd, map, 0);
	map_size_value = (map->height) * (map->width);
	map->p_map = (t_coord *)malloc(sizeof(t_coord) * map_size_value);
	if (!(map->p_map))
		ft_perror("ERROR: Invalid map malloc");
	//fd = open(file_name, O_RDONLY);
}

static void	get_map_size(int fd, t_map *map, int i)
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
		check_width = check_color(arr, i); //i = 0;
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