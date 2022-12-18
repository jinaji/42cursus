#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <poll.h>
#include <vector>
#include "../includes/in.h"

void error(std::string str)
{
	std::cerr << str << std::endl;
	exit (1);
}

int main(int ac, char **av)
{
	char received[256];
	std::vector<pollfd> pfds;


	if (ac == 1)
		error("ac");
	std::string port = static_cast<std::string>(av[1]);


	int fd = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << fd << std::endl;
	
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(atoi(av[1]));

	if (bind (fd, (struct sockaddr *)&address, sizeof(address)) < 0)
		error("bind");
	
	if (listen(fd, address.sin_port) < 0)
		error("listen");
	
	pfds.push_back(pollfd());
	pfds.back().fd = fd;
	pfds.back().events = POLLIN;


	socklen_t csin_len = sizeof(address);
	int c_fd = accept(fd, (struct sockaddr *)&address, &csin_len);
	bool check = true;
	while (check)
	{
		int len = recv(c_fd, received, sizeof(received), 0);
		received[len] = 0;
		std::cout << received << std::endl;
		// send(c_fd, received, sizeof(received) - 1, 0);

		// check = false;
	}

	close (fd);
	close (c_fd);
}