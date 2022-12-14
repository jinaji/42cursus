# ft_irc

## socket
```c++
Syntax
#include <sys/types.h>
#include <sys/socket.h>

int socket(int address_family, int type, int protocol);
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
#include <sys/socket.h>

int setsockopt(int s, int  level,  int  optname,  const  void  *optval, socklen_t optlen);
```
### 설명
소켓의 옵션을 설정한다.
- s: 옵션을 설정할 소켓 디스크립터.
- level: optname 값이 socket level인지 특정 프로토콜에 대한 설정인지를 지정하는 값. 보통 SOL_SOCKET와 IPPROTO_TCP 중 하나를 사용.
- optname: 설정을 위한 소켓옵션의 번호.
- optval: 설정값을 저장하기 위한 버퍼의 포인터. <br>
설정값을 void * 로 넘기는 이유는 설정하고자 하는 소켓옵션에 따라서, boolean, interger, 구조체등 다양한 크기를 가지는 데이터형이 사용되기 때문이다. 만약 변경하고자 하는 소켓옵션이 boolean값을 사용한다면, 0혹은 1값을 사용하면 된다.
- optlen: optval 버퍼의 크기.
### 반환값
- 1 (unsuccessful)
- 0 (successful)

## getsockname
```c++
Syntax
#include <sys/socket.h>

int getsockname(int s, struct sockaddr *name, socklen_t *namelen);
```
### 설명
### 반환값

## getprotobyname
```c++
Syntax
```
### 설명
### 반환값

## gethostbyname
```c++
Syntax
```
### 설명
### 반환값

## getaddrinfo
```c++
Syntax
```
### 설명
### 반환값

## freeaddrinfo
```c++
Syntax
```
### 설명
### 반환값

## bind
```c++
Syntax
```
### 설명
### 반환값

## connect
```c++
Syntax
```
### 설명
### 반환값

## listen
```c++
Syntax
```
### 설명
### 반환값

## accept
```c++
Syntax
```
### 설명
### 반환값

## htons
```c++
Syntax
```
### 설명
### 반환값

## htonl
```c++
Syntax
```
### 설명
### 반환값

## ntohs
```c++
Syntax
```
### 설명
### 반환값

## ntohl
```c++
Syntax
```
### 설명
### 반환값

## inet_addr
```c++
Syntax
```
### 설명
### 반환값

## inet_ntoa
```c++
Syntax
```
### 설명
### 반환값

## send
```c++
Syntax
```
### 설명
### 반환값

## recv
```c++
Syntax
```
### 설명
### 반환값

## signal
```c++
Syntax
```
### 설명
### 반환값

## lseek
```c++
Syntax
```
### 설명
### 반환값

## fstat
```c++
Syntax
```
### 설명
### 반환값

## fcntl
```c++
Syntax
```
### 설명
### 반환값

## kqueue
```c++
Syntax
```
### 설명
### 반환값
