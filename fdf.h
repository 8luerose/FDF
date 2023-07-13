/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkwon <taehkwon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:05:46 by taehkwon          #+#    #+#             */
/*   Updated: 2023/07/13 16:56:15 by taehkwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

// # include "./mlx/mlx.h"
# include "./mlx2/mlx.h"

# include "./get_next_line/get_next_line.h"

# include <stdio.h>

// # define WIDTH 1800
// # define HEIGHT 1000
# define WIDTH 2000
# define HEIGHT 1500
# define TEST 1000

typedef struct s_coord
{
	int		color;
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_map
{
	int		width;
	int		height;
	t_coord	*p_map;
}	t_map;

typedef struct s_vars
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

typedef struct s_dda
{
	double	dx;
	double	dy;
	double	x_inc;
	double	y_inc;
	double	step;
}	t_dda;


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
int		invalid_color_check(char **arr, int i);
int		is_valid_num(char *arr);
int		is_color(char *arr);
void	parsing(char *file_name, t_map *map);
void	set_map_size(int fd, t_map *map, int i);
void	set_map_coord(int fd, t_map *map, int x, int y);
void	get_map_color(char *arr, t_coord *coord);
int		input_color(char *arr, char *hex, int len);
int		hex_indexing(char *hex, char x);


void	isometric(t_map *map);
void	rotate_x(double *x, double *y, double *z);
void	rotate_y(double *x, double *y, double *z);
void	rotate_z(double *x, double *y, double *z);

void	set_mlx(t_vars *vars, t_image *image);

// void	image_size_up(t_vars *vars, t_map *map);
void	image_size_up(t_map *map);
int		max_gap(t_map *map);


// void	draw_img(t_image *image, t_map *map);

void	draw_col(t_image *img, t_map *map);
void	draw_row(t_image *img, t_map *map);
void	DDA(t_image *img, t_map *map, t_coord first, t_coord second);
void	DDA_inc(t_image *image, t_map *map, t_dda *dda, t_coord *p);
void	pixel_input_color(t_image *image, int x, int y, int color);

void	print_mlx(t_vars *vars, t_image *image);
int		quit_window(int ket_code, t_vars *vars);

#endif