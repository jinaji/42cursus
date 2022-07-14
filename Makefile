# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/07/14 20:53:10 by jinkim2          ###   ########seoul.kr   #
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
NAME_BONUS = pipex

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $^ -Llibft -lft

bonus: $(OBJS_BONUS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME_BONUS) $^ -Llibft -lft

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean re
