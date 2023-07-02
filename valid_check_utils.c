/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:33:22 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 20:25:45 by taehkwon         ###   ########.fr       */
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
	if (len < 3)
		return (0);
	result = 0;
	if (ft_strncmp(arr[len - 1], "fdf", 4) == 0)
		result = 1;
	free_for_split(arr);
	return (result);
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
}