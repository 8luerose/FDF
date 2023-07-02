/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:54:08 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 21:05:15 by taehkwon         ###   ########.fr       */
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

	i = 0;
	printf("test2: %s\n", arr);
	printf("len: %d\n", ft_strlen(arr));
	if (arr[i] == '-' || arr[i] == '+')
		i++;
	if (arr == NULL || arr[i] == '\0' || arr[i] == '\n')
		return (0);

	printf("test2: %d %c\n", i, arr[i]);
	
	printf("#-\n");
	while (arr[i] != '\0' && arr[i] != '\n')
	{
		printf("%d\n",arr[i]);
		if (!(arr[i] >= '0' && arr[i] <= '9'))
		{
			// printf("if: %d\n", arr[i]);
			return (0);
		}
		i++;
	}

	printf("end test\n");
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

int	hex_indexing(char *hex, char ch)
{
	int	i;

	i = 0;
	while (hex[i])
	{
		if (hex[i] == ft_tolower(ch))
			return (i);
		i++;
	}
	return (-1);
}