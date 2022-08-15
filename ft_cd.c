#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i = chdir("../pipex");
	printf("%d\n", i);

	system("pwd");
}
