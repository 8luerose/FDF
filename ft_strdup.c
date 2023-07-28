/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:50:11 by taehkwon          #+#    #+#             */
/*   Updated: 2023/06/29 20:13:42 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strdup(const char *s1)
{
	char	*arr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	arr = (char *)malloc((len + 1) * (sizeof(char)));
	if (!(arr))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[len] = '\0';
	return (arr);
}
