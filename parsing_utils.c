/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:54:08 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/01 20:01:47 by taehkwon         ###   ########.fr       */
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

int	color_check(char **arr, int	i)
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