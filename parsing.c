/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:37:34 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/29 20:25:07 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *s)
{
	if (!s)
		return ;
	write (1, s, ft_strlen(s));
	exit(1);
}

int	is_valid_file(char *file_name)
{
	int		result;
	int		len;
	int		**arr;
	int		i;

	result = 0;
	len = 0;
	arr = ft_split(file_name, '.');
	if (!file_name)
		print_error("split error");
	while (file_name[len] != 0)
		len++;
	if (ft_strncmp(file_name[len - 1], "fdf", 4) == 0)
		result = 1;
	i = -1;
	while (++i < len)
		free(file_name[i]);
	free(file_name);
	return (result);
}
