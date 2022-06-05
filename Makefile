# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/06/05 16:00:50 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	deque.c		\
		push.c		\
		rotate.c	\
		rrotate.c	\
		sort.c		\
		swap.c
OBJS = ${SRCS:.c=.o}
LIBFT_DIR = libft
LIBFT = libft.a
NAME = push_swap

all: $(NAME) 

$(NAME): $(OBJS) 
	ar crs $(NAME) $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re
