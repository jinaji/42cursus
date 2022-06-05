# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/06/05 19:44:16 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g 
SRCS = 	deque.c			\
		deque_utils.c	\
		push.c			\
		rotate.c		\
		rrotate.c		\
		sort.c			\
		sort_three.c	\
		sort_utils.c	\
		swap.c			\
		main.c
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = libft
LIBFT = libft.a
NAME = push_swap

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)/
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
