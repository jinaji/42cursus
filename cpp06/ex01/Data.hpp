#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>

typedef struct s_data 
{
	int data;
}				Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

//https://blockdmask.tistory.com/242
/*
reintetpret cast - 임의의 포인터 타입끼리 변환 허용 
expression 에 해당하는 걸 new_type으로 비트 단위 변환
int -> int* 보다 struct 안의 int -> int* 가 안전? 하다는 듯 ??
*/

#endif