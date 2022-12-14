# ft_irc

## socket
```c++
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
- -1 (unsuccessful)
- n (successful), where n is a socket descriptor.

## setsockopt
```c++
#include <sys/socket.h>

int setsockopt(int s, int  level,  int  optname,  const  void  *optval, socklen_t optlen);
```
### 설명
소켓의 옵션을 설정한다.
- s: 옵션을 설정할 소켓 디스크립터.
- level: optname 값이 socket level인지 특정 프로토콜에 대한 설정인지를 지정하는 값. 보통 SOL_SOCKET와 IPPROTO_TCP 중 하나를 사용.
- optname: 설정을 위한 소켓옵션의 번호.
- optval: 설정값을 저장하기 위한 버퍼의 포인터. <br>
설정값을 void * 로 넘기는 이유는 설정하고자 하는 소켓옵션에 따라서, boolean, interger, 구조체등 다양한 크기를 가지는 데이터형이 사용되기 때문. 만약 변경하고자 하는 소켓옵션이 boolean값을 사용한다면, 0혹은 1값을 사용.
- optlen: optval 버퍼의 크기.
### 반환값
- -1 (unsuccessful)
- 0 (successful)

## getsockname
```c++
#include <sys/socket.h>

int getsockname(int socket_descriptor, struct sockaddr *local_address, socklen_t *address_length);
```
### 설명
소켓 디스크립터에 할당된 자신의 address를 얻기 위해 사용한다.
- socket_descriptor: 소켓 디스크립터
- local_address: 자신의 주소를 저장할 버퍼
- address_length: 두번째 파라미터 local_address 구조체의 크기를 설정하고 함수를 호출. getsockname() 함수가 끝나면 실제로 local_address 채워진 사이즈가 저장.
### 반환값
- -1 (unsuccessful)
- 0 (successful)

## getprotobyname
```c++
#include <netdb.h>

struct protoent *getprotobyname(const char *protocol_name);
```
### 설명
프로토콜 이름과 protocol_name 일치하는 데이터베이스 항목에 대한 protoent 구조체를 반환합니다.
- protocol_name: 검색할 프로토콜의 이름

### 반환값
- NULL (unsuccessful)
- p (successful), where p is a pointer to struct protoent
```c++
struct protoent {
        char            *p_name;
        char            **p_aliases;
        int             p_proto;
      };
```

## gethostbyname
```c++
#include <netdb.h>

struct hostent *gethostbyname(const char *host_name);
```
### 설명
서버 이름 또는 도메인(예. www.it-note.kr)으로부터 주소정보(IP Address)를 얻습니다. 주소 정보는 local computer의 /etc/hosts 파일 또는 DNS 서버로 부터 주소 정보를 얻습니다.
- host_name: IP 주소를 얻으려는 서버 이름 또는 서버에 대한 도메인명
### 반환값
- NULL (unsuccessful)
- p (successful), where p is a pointer to struct hostent.
```c++
struct hostent {
        char   *h_name;
        char   **h_aliases;
        int    h_addrtype;
        int    h_length;
        char   **h_addr_list;
      };
```

## getaddrinfo
```c++
#include  <sys/socket.h>
#include  <netdb.h>
  
int getaddrinfo(const char *nodename, const char *servname, const struct addrinfo *hints, struct addrinfo **res);
```
### 설명
domain address를 받아서 네트워크 주소 정보(IP address)를 가져온다.
- nodename: 호스트 이름
- servname: 서비스 이름
- hints: addrinfo 구조체를 채워서 넘기면, 이 함수는 addrinfo 구조체의 멤버 변수 값을 읽어서, 이에 대한 주소 정보를 넘김.
```c++
struct addrinfo {
        int     ai_flags;     /* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST, .. */
        int     ai_family;    /* AF_xxx */
        int     ai_socktype;  /* SOCK_xxx */
        int     ai_protocol;  /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
        socklen_t ai_addrlen; /* length of ai_addr */
        char   *ai_canonname; /* canonical name for nodename */
        struct sockaddr  *ai_addr; /* binary address */
        struct addrinfo  *ai_next; /* next structure in linked list */

        int     ai_eflags;    /* Extended flags for special usage */
      };
```
- res: 힌트 값을 참고해서 가져온 네트워크 주소 정보는 res를 통해서 가져 옴.
### 반환값
- 0 (successful)
- non-zero (unsuccessful)

## freeaddrinfo
```c++
void freeaddrinfo(struct addrinfo *res);
```
### 설명
getaddrinfo() 함수의 사용을 끝낸 뒤 freeaddrinfo() 함수를 사용하여 메모리를 해제해야 한다.
- res: 해제할 addrinfo.
### 반환값

## bind
```c++
#include <sys/socket.h>

int bind(int socket_descriptor, const struct sockaddr *local_address, socklen_t address_length);
```
### 설명
소켓에 IP주소와 포트번호를 지정한다. 소켓을 통신에 사용할 수 있도록 준비가 된다. (소켓에 주소를 할당)
- socket_descriptor: 소켓 디스크립터.
- local_address: 할당될 주소.
        - 주소 정보로 인터넷을 이용하는 AF_INET인지 시스템 내에서 통신하는 AF_UNIX에 따라서 달라짐
	- 인터넷을 통해 통신하는 AF_INET인 경우 struct sockaddr_in을 사용
	- 시스템 내부 통신인 AF_UNIX인 경우에는 struct sockaddr을 사용
	```c++
	struct sockaddr_in {
		sa_family_t			sin_family;
		unsigned short int	sin_port;
		struct in_addr		sin_addr;
		unsigned char		__pad[__SOCK_SIZE__ - sizeof(short int) - sizeof(unsigned short int) - sizeof(struct in_addr)];
	};
        
	struct sockaddr {
		sa_family_t			sa_family;
		char				sa_data[14];
	};
        ```
- address_length: local_address 구조체의 크기.
### 반환값
- -1 (unsuccessful)
- 0 (successful)

## connect
```c++
#include <sys/socket.h>

int connect(int socket_descriptor, const struct sockaddr *destination_address, socklen_t address_length);
```
### 설명
생성한 소켓을 통해 서버로 접속을 요청한다.
- socket_descriptor: 소켓 디스크립터.
- destination_address: 서버 주소 정보에 대한 포인터.
- address_length: destination_address의 크기
### 반환값
- -1 (unsuccessful)
- 0 (successful)

## listen
```c++
#include <sys/socket.h>

int listen(int socket_descriptor, int back_log);
```
### 설명
이 함수는 sockfd로 제공된 소켓을 정적으로 마크한다. 즉, accept()를 사용하여 들어오는 연결 요청을 받는데 사용하는 소켓이다.
SOCK_STREAM, SOCK_SEQPACKET 등의 연결지향형 socket에 대해서 server socket을 활성화하여 client의 접속을 허용한다. client의 접속 요청에 대해 accept를 통해 연결이 맺어지고 accept되지 못한 요청은 backlog의 크기만큼 queue에 쌓인다. backlog의 크기보다 많은 Connection이 쌓이면 Client는 ECONNREFUSED 오류가 발생한다.
- socket_descriptor: 소켓 디스크립터. (해당 디스크립터를 생성하는 socket 함수의 2번째 파라미터인 type이 SOCK_STREAM, SOCK_SEQPACKET과 같은 연결지향형이어야 함)
- back_log: 연결이 대기할 수 있는 큐의 갯수이다. 만약 backlog에 연결이 모두 찬 상태에서 새로운 연결을 시도한다면, 클라이언트는 ECONNREFUSED 에러를 받게될 것이다. 만약 재전송을 지원하는 프로토콜을 사용한다면 에러를 무시하고 성공할 때까지 재시도를 하게 된다.
### 반환값
- -1 (unsuccessful)
- 0 (successful)

## accept
```c++
#include <sys/socket.h>

int accept(int socket_descriptor, struct sockaddr *address, socklen_t *address_length);
```
### 설명
client의 접속 요청을 받아들여 client와 연결합니다. accept 함수의 결과로 client와 연결을 유지하는 새로운 socket을 생성합니다. socket() 호출 시 type이 SOCK_STREAM, SOCK_SEQPACKET과 같은 연결지향성 소켓이어야 합니다.
- socket_descriptor: 소켓 디스크립터. (bind 및 listen이 완료된 상태)
- address: 접속한 client의 주소 정보를 저장(설정하는 값이 아니라 얻는 값). address NULL을 넘기면, client 주소 정보를 받지 않겠다는 의미. 연결이 성공되면 이 구조체를 채워서 되돌려 주게 되고, 우리는 이구조체의 정보를 이용해서 연결된 클라이언트의 인터넷 정보를 알아낼수 있다.
- address_length: address 크기
### 반환값
- -1 (unsuccessful)
- n (successful), where n is a socket descriptor.

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
#include <unistd.h>

 off_t lseek(int file_descriptor, off_t offset, int whence);
```
### 설명
현재 파일의 오프셋을 새로운 포지션으로 변경. 새 포지션은 whence 포지션에서 offset 바이트만큼 떨어진 곳.
lseek() 사용 후엔 I/O 오퍼레이션이 새 위치에서 시작됨.
현재 파일의 EOF를 넘어선 곳에 새로운 파일 오프셋을 지정할 경우 이 데이터과 파일의 이전 끝 사이의 간격에서 수행되는 read 오퍼레이션이 이진수 0을 포함하는 바이트를 반환 (먼씹?)
open()에서 O_TEXTDATA / O_CCSID 플래그가 적용된 경우 몇 가지 중요한 고려사항이 있음...

- file_descriptor: 파일 디스크립터
- offset: 오프셋을 변경할 바이트 수. 음수가 들어오면 뒤로 양수가 들어오면 앞으로 움직임.
- whence: <unistd.h> 헤더에 정의된 옵션
SEEK_SET - 파일의 시작
SEEK_CUR - 현재 오프셋
SEEK_END - EOF
whence의 비트가 위의 값이 아닌 다른 값으로 설정되면 실패 후 EINVAL 오류 발생
### 반환값
- -1 (unsuccessful)
- value (successful) - 새 파일 오프셋이 시작 지점에서 몇 바이트 떨어져있는지
## fstat
```c++
Syntax
 #include <sys/stat.h>

 int fstat(int descriptor, struct stat *buffer)
```
### 설명
인자로 받은 open 상태의 디스크립터의 상태를 받아오고 buffer에 정보를 저장.
상태 정보는 <sys/stat.h> 헤더 파일에 정의된 stat 구조체로 반환.
- descriptor: 디스크립터
- buffer: stat 구조체 유형의 버퍼 포인터
소켓 디스크립터에는 st_mode, st_dev(-1), st_blksize(시스템에서 결정하는 최적의 값)만 정해져있음.                                                                                                                                                                                             
### 반환값
- -1 (unsuccessful)
- 0 (successful)
## fcntl
```c++
Syntax
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>

 int fcntl(int descriptor, int command, ...)  
```
### 설명
열려있는 파일 또는 소켓 디스크립터의 변수를 가져오거나 변경하는 등 다양한 작업을 수행함.
- descriptor: 명령어가 적용될 디스크립터
- command: 들어온 디스크립터에 적용될 명령어. 몇몇 명령어는 필요에 따라 매개변수를 더 받음
### 반환값
- -1 (unsuccessful)
- command's value (successful)

## kqueue
```c++
Syntax
```
### 설명
### 반환값
