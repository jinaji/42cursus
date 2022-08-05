CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread

SRCS = main.c
OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(NAME): $(OBJS)

debug:
	cc -g $(CFLAGS) $(OBJS)

clean:
	rm -r $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean bonus re