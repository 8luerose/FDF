/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:46 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/01 20:09:53 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

// # include "mlx.h"
# include "./mlx2/mlx.h"

# include "./get_next_line/get_next_line.h"

# include <stdio.h>

typedef struct	s_coord
{
	int		color;
	double	x;
	double	y;
	//double	z;
}	t_coord;

typedef struct	s_map
{
	int		width;
	int		height;
	t_coord	*p_map;
}	t_map;


int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_valid_file(char *file);
void	free_for_split(char	**str);
void	ft_perror(char *s);
int		get_width(char *line);
int		color_check(char **arr, int	i);

#endif