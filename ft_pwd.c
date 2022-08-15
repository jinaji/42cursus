#include <unistd.h>
#include <stdio.h>
#include <sys/param.h>

int main()
{
	char	buf[1024];

	printf("%s\n", getcwd(buf, 1024));

}
