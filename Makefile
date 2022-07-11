# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/07/12 02:59:05 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
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
		push_swap.c		
		
OBJS = ${SRCS:.c=.o}

NAME_BONUS = checker

SRCS_BONUS = 	get_next_line.c			\
				get_next_line_utils.c	\
				argu_check_bonus.c		\
				count_command_bonus.c	\
				deque_bonus.c			\
				deque_utils_bonus.c		\
				do_command_bonus.c		\
				push_bonus.c			\
				rotate_bonus.c			\
				rrotate_bonus.c			\
				sort_bonus.c			\
				sort_three_bonus.c		\
				sort_utils_bonus.c		\
				swap_bonus.c			\
				push_swap_bonus.c
			
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT_DIR = libft/
LIBFT = libft.a

NAME = push_swap

# ifdef BONUS_CHECK
# 	BONUS = $(OBJS) $(OBJS_BONUS)
# else
# 	BONUS = $(OBJS)
# endif


all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $^ -Llibft -lft

lldb: 
	gcc -g $(SRCS_BONUS) libft/*.c

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME_BONUS) $^ -Llibft -lft
# BONUS_CHECK=1

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean re bonus
