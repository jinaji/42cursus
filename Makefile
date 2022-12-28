NAME = ircserv

NETWORK_SRCS = $(addprefix ./src/network/, Server.cpp Client.cpp Channel.cpp)
COMMAND_SRCS = $(addprefix ./src/command/, Command.cpp Pass.cpp Nick.cpp User.cpp Quit.cpp Oper.cpp Join.cpp Part.cpp Topic.cpp Names.cpp List.cpp Invite.cpp Kick.cpp Mode.cpp Privmsg.cpp Notice.cpp Numerics.cpp)

SRCS = src/main.cpp $(NETWORK_SRCS) $(COMMAND_SRCS)
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
