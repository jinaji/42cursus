CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	argument.c		\
		check.c			\
		philo.c  		\
		routine.c		\
		utils.c

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
