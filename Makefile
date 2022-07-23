
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	get_next_line.c 		\
		get_next_line_utils.c	\
		image.c					\
		map_check.c				\
		move.c					\
		utils.c					\
		so_long.c

SRCS_BONUS =	get_next_line_bonus.c 		\
				get_next_line_utils_bonus.c	\
				image_bonus.c					\
				map_check_bonus.c				\
				move_bonus.c					\
				utils_bonus.c					\
				so_long_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

MLX_DIR = ./mlx
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft

NAME = so_long
NAME_BONUS = so_long_bonus

all:  $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cc -g -o $(NAME) $^ $(MLX_FLAGS) -Llibft -lft

debug : 
	cc -g -o $(NAME) $(SRCS_BONUS) $(MLX_FLAGS) -Llibft -lft

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $?

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	cc -o $(NAME_BONUS) $^ $(MLX_FLAGS) -Llibft -lft

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re : 
	make fclean
	make all

.PHONY = all clean fclean re bonus
