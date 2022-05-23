#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd1 = open("test", O_RDONLY);
	int fd2 = open("test", O_RDONLY);
	// int fd3 = open("test", O_RDONLY);

	char *s1 = get_next_line(fd1);
	char *s2 = get_next_line(fd2);
	// char *s3 = get_next_line(fd3);

	while (s1)
	{
		// s3 = get_next_line(fd3);
		printf("main %s\n", s1);
		printf("main %s\n", s2);
		// printf("main %s\n", s3);
		free(s1);
		free(s2);
		s1 = get_next_line(fd1);
		s2 = get_next_line(fd2);
<<<<<<< HEAD
>>>>>>> f7010aa (done)
=======
>>>>>>> 929b455 (realdone)
		// free(s3);
	}
	 system("leaks a.out | grep 'LEAK'");
}