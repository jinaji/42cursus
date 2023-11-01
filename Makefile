NAME			=	cub3D

FLAGS			=	-Wall -Wextra -Werror -g3
S_FLAGS			=	-framework OpenGL -framework AppKit
CC				=	cc

UTILS			=	ft_atoi.c \
					ft_memset.c \
					ft_split.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_strtrim.c \
					ft_strncmp.c \
					ft_substr.c \
					ft_isdigit.c \
					ft_isspace.c \
					get_next_line.c \
					get_next_line_utils.c \
					utils.c \

RAY				=	ray_casting.c \

PARSER			=	parsing.c \
					parsing_utils.c \
					parsing_text.c \
					parsing_rgb.c \
					parsing_map.c \
					parsing_map_utils.c \
					parsing_map_utils2.c

HOOK			=	hooks.c \
					look.c \
					move.c \

DRAW			=	pixel.c \
					draw.c \


DIR_OBJS		=	obj
DIR_MLX			=	mlx

SRCS			=	$(addprefix srcs/parsing/, $(PARSER))		\
					$(addprefix srcs/utils/, $(UTILS))		\
					$(addprefix srcs/hook/, $(HOOK))			\
					$(addprefix srcs/ray/, $(RAY))			\
					$(addprefix srcs/draw/, $(DRAW))			\
					srcs/cub3D.c

OBJS			=	$(addprefix obj/,$(SRCS:%.c=%.o))

AR_MLX			=	$(DIR_MLX)/libmlx.a

all				:	$(DIR_OBJS) $(NAME)

$(DIR_OBJS)/%.o	:	%.c
					mkdir -p $(@D)
					$(CC) $(FLAGS) -Imlx -c $< -o $@

#arch -x86_64
$(NAME)			:	$(AR_MLX) $(OBJS)
					$(CC) $(FLAGS) $(S_FLAGS) $(OBJS) $(AR_MLX) -o $(NAME)

$(DIR_OBJS)		:
					mkdir -p $@

$(AR_MLX)		:
					make -C $(DIR_MLX)

clean			:
					rm -rf $(DIR_OBJS)
					make clean -C $(DIR_MLX)

fclean			:
					rm -rf $(DIR_OBJS)
					make clean -C $(DIR_MLX)
					rm -rf $(NAME)

re				:	fclean all

.PHONY			:	re fclean clean all
