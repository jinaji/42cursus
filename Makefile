# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/06/05 22:26:58 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	argu_check.c	\
		deque_utils.c	\
		deque.c			\
		push.c			\
		rotate.c		\
		rrotate.c		\
		sort_three.c	\
		sort_utils.c	\
		sort.c			\
		swap.c			\
		main.c			\
		argu_check.c
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = libft/
LIBFT = libft.a
NAME = push_swap

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME) $^ -Llibft -lft
	make clean

lldb: 
	gcc -g *.c libft/*.c 

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean re
