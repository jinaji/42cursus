# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/07/18 21:30:10 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	command.c	\
		execute.c	\
		path.c		\
		utils.c		\
		pipex.c
		
OBJS =	$(SRCS:.c=.o)

SRCS_BONUS =	command.c				\
				execute_bonus.c			\
				get_next_line.c			\
				get_next_line_utils.c	\
				path.c					\
				utils.c					\
				pipex_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_DIR = libft/
LIBFT = libft.a

NAME = pipex

ifdef B_C
	OBJ_FILES = $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $^ -Llibft -lft

bonus:
	make B_C=1 

lldb:
	cc -g $(OBJS_BONUS) libft/*.c

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean bonus re
