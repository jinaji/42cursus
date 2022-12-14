.DEFAULT_GOAL := all

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -ferror-limit=100 -g -MMD -MP
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)  

NAME = a.out

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:
	$(RM) -r $(OBJS) $(DEPS)

fclean: clean
	$(RM) -r $(NAME) $(DEPS)

re: fclean all

.PHONY: all clean fclean re