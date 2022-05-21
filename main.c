#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("test", O_RDONLY);
	char	*str = "1";

	while (str)
	{
		str = get_next_line(fd);
		printf("main %s\n", str);
	}
	system("leaks a.out | grep 'LEAK'");
}