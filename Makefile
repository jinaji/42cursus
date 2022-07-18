
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	so_long.c
		
OBJS = ${SRCS:.c=.o}

MLX_DIR = ./mlx
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

NAME = so_long

all:  $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	cc -o $(NAME) $^ $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY = all clean fclean re bonus
