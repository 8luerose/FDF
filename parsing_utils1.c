/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:54:08 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 04:00:16 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	int		len_width;
	char	**arr;

	len_width = 0;
	arr = ft_split(line, ' ');
	while (arr[len_width])
		len_width++;
	free_for_split(arr);
	return (len_width);
}

int	invalid_color_check(char **arr, int	i)
{
	char	**color_split;
	int		color_split_cnt;

	while (arr[i])
	{
		color_split = ft_split(arr[i], ',');
		if (!color_split)
		{
			free_for_split(color_split);
			return (0);
		}
		color_split_cnt = 0;
		while (color_split[color_split_cnt])
			color_split_cnt++;
		if (color_split_cnt > 3)
		{
			free_for_split(color_split);
			return (0);
		}
		free_for_split(color_split);
		i++;
	}
	return (i);
}

int	is_valid_num(char *arr)
{
	int	i;

	if (arr[i] == '-' || arr[i] == '+')
		i++;
	if (arr == NULL || arr[i] == '\0' || arr[i] == '\n')
		return (0);
	while (arr[i] != '\0' || arr[i] != '\n')
	{
		if (!(arr[i] >= 0 && arr[i] <= 9))
			return (0);
		i++;
	}
	return (1);
}

int	is_color(char *arr)
{
	char	**color_split;
	int		color_split_cnt;

	color_split = ft_split(arr, ',');
	if (!color_split)
	{
		free_for_split(color_split);
		return (0);
	}
	color_split_cnt = 0;
	while (color_split[color_split_cnt])
		color_split_cnt++;
	if (color_split_cnt > 3)
	{
		free_for_split(color_split);
		return (0);
	}
	free_for_split(color_split);
	return (color_split_cnt);
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