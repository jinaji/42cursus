#include "../../include/network/Server.hpp"
#include "../../include/in.h"

Server::Server(const std::string port, const std::string pass): _port(port), _pass(pass)
{

}

Server::~Server()
{

}

void    Server::loop()
{
    char received[256];
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	
    struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	// address.sin_port = htons(atoi(getPort()));
    address.sin_port = htons(stoi(getPort()));

    if (bind (fd, (struct sockaddr *)&address, sizeof(address)) < 0)
		return ;
	
	if (listen(fd, address.sin_port) < 0)
		return ;

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

std::string Server::getPort() { return _port; }
std::string Server::getPass() { return _pass; }