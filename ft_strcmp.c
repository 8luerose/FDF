/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:42:50 by taehkwon          #+#    #+#             */
/*   Updated: 2023/08/03 18:43:42 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	case1;
	unsigned char	case2;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		case1 = (unsigned char)s1[i];
		case2 = (unsigned char)s2[i];
		if (case1 != case2)
			return (case1 - case2);
		i++;
	}
	return (0);
}
