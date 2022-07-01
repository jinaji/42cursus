# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/07/01 20:42:27 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = 	pipexx.c get_next_line.c get_next_line_utils.c
		
OBJS = ${SRCS:.c=.o}

LIBFT_DIR = libft/
LIBFT = libft.a

NAME = pipex

all: $(NAME) 

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $^ -Llibft -lft
	make clean

lldb: 
	cc -g pipexx.c libft/*.c get_next_line.c get_next_line_utils.c

bonus: $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	cc -o $(BONUS) $^ -Llibft -lft
	make clean

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY = all clean fclean re
