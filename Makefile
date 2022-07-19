
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	so_long.c get_next_line.c get_next_line_utils.c
		
OBJS = ${SRCS:.c=.o}

MLX_DIR = ./mlx
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft

NAME = so_long

all:  $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $^ $(MLX_FLAGS) -Llibft -lft

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY = all clean fclean re bonus
