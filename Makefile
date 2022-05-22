# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:18:55 by jinkim2           #+#    #+#              #
#    Updated: 2022/05/22 14:09:10 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -fsanitize=address
SRCS = 	main.c\
		get_next_line_bonus.c\
		get_next_line_utils_bonus.c
OBJS = ${SRCS:.c=.o}
NAME = test.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY = all clean fclean re
