CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = Account.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = account

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean bonus re