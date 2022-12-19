#include "../../include/network/Server.hpp"

Server::Server(const std::string port, const std::string pass): _port(port), _pass(pass) {}

Server::~Server() {}

std::string Server::getPort() { return _port; }

std::string Server::getPass() { return _pass; }

void    Server::makesock()
{
	// socket()
	if ((_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw std::runtime_error("socket 에러");
	
	// setsockopt() https://www.joinc.co.kr/w/Site/Network_Programing/AdvancedComm/SocketOption
	// bool opt = false;
	// // int opt = 1;
	// if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt) * 4) == -1)
	// 	throw std::runtime_error("setsockopt 에러");

	// fcntl() https://reakwon.tistory.com/110
	if (fcntl(_sock, F_SETFL, O_NONBLOCK) == -1)
		throw std::runtime_error("fcntl 에러");

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(stoi(getPort()));

	// memset(&address, 0, sizeof(sockaddr_in));

	// bind()
	if (bind(_sock, (struct sockaddr *) &address, sizeof(address)) == -1)
		throw std::runtime_error("bind 에러");

	// listen() https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=bomyzzang&logNo=220428023194
	//			https://velog.io/@techy-yunong/socket-programming-listen-API-backlog
	if (listen(_sock, 1024) == -1)
		throw std::runtime_error("listen 애러");
	FD_ZERO(&_read_fd);
	FD_SET(_sock, &_read_fd);
	_fd_max = _sock;
}

void    Server::loop()
{
	std::string	input;
	int clnt_fd;
	struct sockaddr_in clnt_adr;
	while(1)
	{
		_cp_read = _read_fd;
		// select() https://1d1cblog.tistory.com/356
		//			https://couplewith.tistory.com/entry/%EC%86%8C%EC%BC%93-multi-thread%EB%A5%BC-%ED%99%9C%EC%9A%A9%ED%95%9C-%EC%86%8C%EC%BC%93-%EC%84%9C%EB%B2%84-%EA%B0%9C%EB%B0%9C
		if (select(_fd_max + 1, &_cp_read, 0, 0, 0) == -1) // 0: 타임아웃, -1: 오류
			throw std::runtime_error("select 에러");
		for (int i = 0; i < _fd_max + 1; i++)
		{
			if (FD_ISSET(i, &_cp_read))
			{
				if (i == _sock)	// fd가 서버소켓이면
				{
					socklen_t adr_sz = sizeof(clnt_adr);
					if ((clnt_fd = accept(_sock, (struct sockaddr *)&clnt_adr, &adr_sz)) == -1)
						std::runtime_error("accept 에러");
					Client clnt(clnt_fd);
					_clnt.push_back(clnt);
					FD_SET(clnt_fd, &_read_fd);
					if (_fd_max < clnt_fd)
						_fd_max = clnt_fd;
				}
				else
				{
					char received[256];
					int len;
					if ((len = recv(i, received, sizeof(received), 0)) <= 0)
					{
						if (len == 0)
							exit(1);
							// user disconnect
						else
							throw std::runtime_error("recv 에러");
					}
					received[len] = 0;
					input = c.str(received);
					cmd.execute(input);
					std::cout << received;
				}
			}
		}
	}
	close(_sock);
	close(clnt_fd);
}