#include "../../include/network/Server.hpp"
#include <termios.h>

Server::Server(const std::string port, const std::string pass): _port(port), _pass(pass) {}

Server::~Server() {}

void    Server::makeSock()
{
	// socket()
	if ((_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		throw std::runtime_error("socket 에러");

	// setsockopt() https://www.joinc.co.kr/w/Site/Network_Programing/AdvancedComm/SocketOption
	// bool opt = false;
	int opt = 1;
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
		throw std::runtime_error("setsockopt 에러");

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

// void set_input_mode(struct termios new_term)
// {
// 		tcgetattr(STDIN_FILENO, &new_term); // STDIN으로부터 터미널 속성을 받아온다
// 			new_term.c_lflag &= ~(ICANON | ECHO);  // ICANON, ECHO 속성을 off
// 		new_term.c_cc[VMIN] = 1;               // 1 바이트씩 처리
// 		new_term.c_cc[VTIME] = 0;              // 시간은 설정하지 않음
// 		tcsetattr(STDIN_FILENO, TCSANOW, &new_term); // 변경된 속성의 터미널을 STDIN에 바로 적용
// }

void    Server::loop()
{
	std::string	input;
	int clnt_fd;
	struct sockaddr_in clnt_adr;
	// struct termios new_term;

	// set_input_mode(new_term);
	// int ch;
	// while (read(0, &ch, sizeof(int)) > 0)
	// {
	// 		if (ch == 4)
	// 				break ;
	// 		else
	// 				write(0, &ch, sizeof(int));
	// 		ch = 0;
	// }
	while(1)
	{
		signal(SIGQUIT, SIG_DFL);
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
						throw std::runtime_error("accept 에러");
					// if (fcntl(clnt_fd, F_SETFL, O_NONBLOCK) == -1)
					// 	throw std::runtime_error("fcntl 에러");
					Client *clnt = new Client(clnt_fd);
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
						received[len] = 0;
						if (len == 0)
						{
							std::cout << "@disconnect@ Client fd: [" << this->disconnectClient(i) << "]\n";
							continue;
						}
						else
							throw std::runtime_error("recv 에러");
					}
					received[len] = 0;
					if (input.find("\n") != std::string::npos)
						input.clear();
					input.append(received);
					if (input.find("\n") == std::string::npos)
						continue;
					Client *user = this->getclientSock(i);
					if (user->getSocket() > 0) // Cntl+C , +D 처리
					{
						Command cmd(input, this->getPass(), *user, *this);
						cmd.execute();
					}
					input.clear();
					// 리눅스 줄내림은 \n, window 줄내림은 \r\n -> nc와 limechat이 다름
				}
			}
		}
	}
	close(_sock);
	close(clnt_fd);
}

int	Server::disconnectClient(int fd)
{
	std::cout << "disconnect " << fd << std::endl;
	for (std::list<Client *>::iterator it = _clnt.begin(); it != _clnt.end(); ++it)
	{
		if ((*it)->getSocket() == fd)
		{
			FD_CLR(fd, &_read_fd);
			for (std::list<Channel>::iterator ite = _chnl.begin(); ite != _chnl.end(); ite++)
			{
				std::string print = ":" + (*it)->getNick() + "!" + (*it)->getUser() + "@127.0.0.1" + " PART " + (*ite).getName() + "\r\n";
				std::map<int, std::string>::iterator iter = (*ite).getParticipantsFd().begin();
				for (; iter != (*ite).getParticipantsFd().end(); iter++)
				{
					std::cout << "out it " << (*ite).getParticipantsKey(iter) << std::endl;
					if ((*ite).getParticipantsKey(iter) != fd)
					{
						std::cout << "send: " << (*ite).getParticipantsKey(iter) << std::endl;
						if (send((*ite).getParticipantsKey(iter), print.c_str(), strlen(print.c_str()), 0) == -1)
							throw std::runtime_error("send error");
						// (*ite).getParticipantsFd().erase(fd);
					}
				}
			}
			for (std::list<Channel>::iterator ite =_chnl.begin(); ite !=_chnl.end(); ite++)
			{
				(*ite).getParticipantsFd().erase(fd);
				// _chnl.erase(it);
			}
			_clnt.remove(*it);
			delete *it;
			close(fd);
			if (_clnt.empty() == true)	// _sock = 3
				_fd_max = _sock;
			else if (_fd_max == fd)
				this->chgFdmax();
			return fd;
		}
	}
	return -1;
}

void	Server::chgFdmax()
{
	for (std::list<Client *>::iterator it = _clnt.begin(); it != _clnt.end(); ++it)
		if ((*it)->getSocket() > _fd_max)
			_fd_max = (*it)->getSocket();
}

Client    *Server::getclientSock(int fd)
{
	for (std::list<Client *>::iterator it = _clnt.begin(); it != _clnt.end(); ++it)
		if ((*it)->getSocket() == fd)
			return (*it);
	return NULL;
}

std::list<Client *> &Server::getClient() { return _clnt; }

std::list<Channel> &Server::getChannel() { return _chnl; }

int	Server::getSock() { return _sock; }

std::string Server::getPort() { return _port; }

std::string Server::getPass() { return _pass; }

int             Server::getFdmax() { return _fd_max; }
