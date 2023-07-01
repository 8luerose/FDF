/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 03:28:10 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 03:37:02 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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