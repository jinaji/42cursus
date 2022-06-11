# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/06/11 17:15:27 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	argu_check.c	\
		count_command.c	\
		deque_utils.c	\
		deque.c			\
		push.c			\
		rotate.c		\
		rrotate.c		\
		sort_three.c	\
		sort_utils.c	\
		sort.c			\
		swap.c			\
		argu_check.c	\
		push_swap.c		
		
OBJS = ${SRCS:.c=.o}

BONUS = checker

BONUS_SRCS = 	get_next_line.c			\
				get_next_line_utils.c	\
				deque_bonus.c			\
				deque_utils_bonus.c		\
				push_bonus.c			\
				rotate_bonus.c			\
				rrotate_bonus.c			\
				sort_utils_bonus.c		\
				swap_bonus.c			\
				argu_check_bonus.c		\
				do_command_bonus.c		\
				push_swap_bonus.c
			
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

LIBFT_DIR = libft/
LIBFT = libft.a

NAME = push_swap

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME) $^ -Llibft -lft
	make clean

lldb: 
	gcc -g $(BONUS_SRCS) libft/*.c

bonus: $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	gcc -o $(BONUS) $^ -Llibft -lft
	make clean

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean re
