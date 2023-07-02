/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:46 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/02 07:17:39 by taehkwon         ###   ########.fr       */
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

# define HEIGHT 1000
# define WIDTH 1000

typedef struct	s_coord
{
	int		color;
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct	s_map
{
	int		width;
	int		height;
	t_coord	*p_map;
}	t_map;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_image
{
	void	*img;
	char	*ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;



int		ft_atoi(const char *str);
int		ft_tolower(int c);
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
int		invalid_color_check(char **arr, int	i);
int		is_valid_num(char *arr);
int		is_color(char *arr);
void	parsing(char *file_name, t_map *map);
void	set_map_size(int fd, t_map *map, int i);
void	set_map_coord(int fd, t_map *map, int x, int y);
void	get_map_color(char *arr, t_coord *coord);
int		input_color(char *arr, char *hex, int len);
int		hex_indexing(char *hex, char x);

void	set_mlx(t_vars *vars, t_image *image);
void	print_mlx(t_vars *vars, t_image *image);
void	quit_window(int ket_code, t_vars *vars);

#endif