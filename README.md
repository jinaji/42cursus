# ft_irc

## socket
```c++
Syntax
  #include <sys/types.h>
  #include <sys/socket.h>

  int socket(int address_family, int type, int protocol)
```
### 설명
해당 소켓을 가리키는 소켓 디스크립터를 반환한다.
- address_family: 소켓에 사용할 address family. (AF_UNIX(프로토콜 내부에서), AF_INET(IPv4), AF_INET6(IPv6))
- type: 원하는 통신 타입(프로토콜). (SOCK_STREAM(TCP))
- protocol: 소켓에 사용할 프로토콜. (IPPROTO_TCP(TCP))
### 반환값
- 1 (unsuccessful)
- n (successful), where n is a socket descriptor.
## setsockopt
```c++
Syntax
  #include <sys/types.h>
  #include <sys/socket.h>

  int socket(int address_family, int type, int protocol)
```
### 설명
몰
### 반환값
라
## getsockname
## getprotobyname
## gethostbyname
## getaddrinfo
## freeaddrinfo
## bind
## connect 
## listen
## accept
## htons
## htonl
## ntohs
## ntohl
## inet_addr
## inet_ntoa
## send
## recv
## signal
## lseek
## fstat
## fcntl
## kqueue
