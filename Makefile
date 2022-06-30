# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/06/30 15:14:35 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = 	pipexx.c
		
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
	cc -g pipexx.c libft/*.c

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
