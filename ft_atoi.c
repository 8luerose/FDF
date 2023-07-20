/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:33:31 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/20 17:05:06 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			length;

	result = 0;
	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	length = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
		length++;
	}
	result = result * sign;
	if (*str != '\0' || length > 10
		|| result > 2147483647 || result < -2147483648)
		ft_perror("ERROR: map->z range error");
	return ((int)result);
}
