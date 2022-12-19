CXX = c++
SRCS = src/main.cpp src/network/Server.cpp src/network/Client.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ircserv
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
