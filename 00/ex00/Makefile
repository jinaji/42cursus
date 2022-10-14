CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp
NAME = megaphone

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean bonus re