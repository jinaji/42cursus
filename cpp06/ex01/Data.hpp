#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>

typedef struct s_data 
{
	int data;
}				Data;

uintptr_t	serialize(Data* ptr); // 데이터를 스트림에 쓰는 것 (직렬화)
Data*		deserialize(uintptr_t raw); // 스트림을 읽어서 데이터로 만드는 것 (역직렬화)

//https://blockdmask.tistory.com/242

#endif