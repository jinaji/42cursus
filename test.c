#include "pipex.h"


int main(int ac, char **av, char **envp)
{/*
	char    *arg1 = "-la";
	char    *argv[] = {"ls", arg1, 0};
	execve("/bin/ls", argv, envp);*/
	int		ret;
	int     fd[2];
	int     openfd;
	pid_t   pid;
	char    buff[1000];

/*
	openfd = open("q", O_RDWR | O_CREAT | O_TRUNC , 00700);
	printf("%d\n", openfd);
	ret = dup2(openfd, STDOUT_FILENO);
	printf("ret %d openfd %d stdout %d\n", ret, openfd, STDOUT_FILENO);

	printf 내용 q에 담김
	*/

/*
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		printf("child p\n");
		close(fd[1]);
		printf("%d %d\n", fd[0], fd[1]);
		read (fd[0], buff, 1000);
		printf("%s\n", buff);
	}
	else
	{
		printf("parent p\n");
		printf("%d %d\n", fd[0], fd[1]);
		close (fd[0]);
		write(fd[1], "parent write\n", 100);
	}
	*/
}
