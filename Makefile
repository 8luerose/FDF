CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Iget_next_line -Imlx
MLX = -Lmlx -lmlx -framework OpenGL -framework Appkit
MLX_DIR = ./mlx

RM = rm -f
NAME = fdf

SRCS =  draw.c                      \
        ft_atoi.c                   \
        ft_memcpy.c                 \
        ft_split.c                  \
        ft_strchr.c                 \
        ft_strdup.c                 \
        ft_strlen.c                 \
		ft_strcmp.c					\
        ft_strncmp.c                \
        ft_substr.c                 \
        ft_tolower.c                \
        isometric_projection.c      \
        main.c                      \
        max_min_xy.c                \
        move_center.c               \
        parsing.c                   \
        parsing_utils.c             \
        scaling.c                   \
        setting_mlx.c               \
        valid_check_utils.c         \
        get_next_line/get_next_line.c    \
        get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) 

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
