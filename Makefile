CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I get_next_line -I mlx
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
NAME = fdf

SRCS =  src/draw.c						\
		src/ft_atoi.c 					\
		src/ft_memcpy.c 				\
		src/ft_split.c 					\
		src/ft_strchr.c 				\
		src/ft_strdup.c 				\
		src/ft_strlen.c 				\
		src/ft_strncmp.c				\
		src/ft_substr.c 				\
		src/ft_tolower.c				\
		src/isometric_projection.c		\
		src/main.c 						\
		src/max_min_xy.c 				\
		src/move_center.c 				\
		src/parsing.c 					\
		src/parsing_utils.c 			\
		src/scaling.c 					\
		src/setting_mlx.c 				\
		src/valid_check_utils.c			\
		get_next_line/get_next_line.c	\
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
