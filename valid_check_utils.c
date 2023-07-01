/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 02:33:22 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 01:33:57 by taehkwon         ###   ########.fr       */
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