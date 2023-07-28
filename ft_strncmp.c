/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:10 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/29 20:10:20 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	case1;
	unsigned char	case2;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		case1 = (unsigned char)s1[i];
		case2 = (unsigned char)s2[i];
		if (case1 != case2)
			return (case1 - case2);
		i++;
	}
	return (0);
}
