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

void    Server::test()
{
	// socket()
	int sock_fd;
	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw std::runtime_error("소켓 에러");
	
	// setsockopt() 왜함
	// bool opt = false;
	// // int opt = 0;
	// if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt) * 4) == -1)
	// 	throw std::runtime_error("소켓 옵션 에러");

}