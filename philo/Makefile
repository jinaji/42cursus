CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

SRCS = philo.c #philo_init.c routine.c utils.c # main.c 
OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

debug:
	cc $(CFLAGS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean bonus re
