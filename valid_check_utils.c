/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:33:22 by taehkwon          #+#    #+#             */
/*   Updated: 2023/08/03 18:41:47 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_file(char *file_name)
{
	int		result;
	int		len;
	char	**arr;

	arr = ft_split(file_name, '.');
	if (!arr)
		ft_perror("split error");
	len = 0;
	while (arr[len] != 0)
		len++;
	if (len < 2)
		return (0);
	result = 0;
	if (ft_strcmp(arr[len - 1], "fdf") != 0)
	{
		free_for_split(arr);
		return (0);
	}
	free_for_split(arr);
	return (1);
}

void	ft_perror(char *s)
{
	if (!s)
		return ;
	write (2, s, ft_strlen(s));
	write (2, "\n", 1);
	exit(1);
}

void	free_for_split(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}
