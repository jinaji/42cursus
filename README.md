
# 42cursus
42Seoul 과정을 진행하며 작성했던 과제의 통합 저장소


### irc
- [RFC 1459](https://datatracker.ietf.org/doc/html/rfc1459) Internet Relay Chat 프로토콜에 맞추어 사용자 입력을 파싱 후 클라이언트로 전달하는 서버를 C++98로 구현
- select 함수를 사용해 IO Multiplexing 구현
- 채널 및 유저 정보 저장 구조 기획

### container
- C++ STL의 vector 내부 구조 분석 후 vector에 제공되는 메소드 구현

### Inception
- VM 환경 내부에서 nginx, mariadb, wordpress 세 개의 Docker container들을 올리고 유기적으로 연결하는 경험을 함
- db와 로컬 볼륨을 마운트시켜 컨테이너를 재가동 시켜도 저장된 정보를 사용할 수 있게 함

### cpp_module
- C++98 환경에서 기본 기능을 익히고 과제에서 요구하는 바를 충족시킴
- 입력값과 출력값을 원하는 대로 가공할 수 있고 간단한 입출력 프로그램을 만들 수 있음
- STL 사용법을 익힘

### philosophers
- 한 프로세스 내에서 멀티스레딩으로 특정 자원을 공유하는 상황 구현
- 멀티스레드 사이에서 일어날 수 있는 데이터 레이스를 방지

### pipex
- 명령어 입력을 받아 shell 의 pipe처럼 작동하는 프로그램 작성
- fork를 이용해 멀티 프로세스를 만들고, 이들을 통신시키기 위해 pipe()로 반환된 다중 fd를 관리

### so_long
- mlx 라이브러리를 이용해 주어지는 맵 파일을 파싱, 정해진 값에 맞추어 이미지를 띄움
- 사용자 입력을 받아 캐릭터를 움직이고 조건을 만족했을 때 프로그램을 종료

### push_swap
- 랜덤하게 주어지는 수의 입력을 두 개의 deque를 이용해 원하는대로 정렬
- 이 과정에서 연산 수를 줄이기 위한 로직 구현

### printf
- C의 printf 함수 구현
- 가변인자를 사용할 수 있고 정해진 서식(%s, %d 등) 에 맞추어 문자열 대치

### get_next_line
- 특정 문자(\n)로 문자열을 나눌 수 있고 이 과정에서 malloc과 free를 사용해 메모리 관리
- 링크드 리스트를 사용할 수 있음
