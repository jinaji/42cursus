#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int	**make_fd(int cmd)
{
	int	**fd;
	int	i;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * cmd);
	if (!fd)
		exit (12);
	while (i < cmd)
	{
		fd[i] = malloc(sizeof(int) * 2);
		if (!fd[i])
			exit (12);
		i++;
	}
	return (fd);
}

void	first_exec(void)
{
	if (left redirection check)
	{
		openfd = open("file", O_RDONLY);
		if (openfd < 0)
			exit(); // 정해진 문구 있음
		dup2(openfd, STDIN_FILENO);
	}
	if (right redirection check)
	{
		if (single)
			outfd = open("file", O_WRONLY, O_CREAT, O_TRUNC);
		else
			outfd = open("file", O_WRONLY, O_CREAT, O_APPEND);
		if (outfd < 0)
			exit();
		dup2(openfd, STDOUT_FILENO);
	}
	else if (cmd != 1)
		dup2(fd[i][WRITE], STDOUT_FILENO);
	execve("path", "cmd with option", envp);
}

void	mid_exec(void)
{
	if (left redirection check)
	{
		openfd = open("file", O_RDONLY);
		if (openfd < 0)
			exit();
		dup2(openfd, STDIN_FILENO);
	}
	if (right redirection check)
	{
		if (single)
			outfd = open("file", O_WRONLY, O_CREAT, O_TRUNC);
		else
			outfd = open("file", O_WRONLY, O_CREAT, O_APPEND);
		if (outfd < 0)
			exit();
		dup2(openfd, STDOUT_FILENO);
	}
	else
	{
		dup2(fd[i - 1][READ], STDIN_FILENO);
		close (fd[i - 1][READ]);
		dup2(fd[i][WRITE], STDOUT_FILENO);
		close (fd[i][WRITE]);
	}
	execve("path", "cmd with option", envp);
}

void	last_exec(void)
{
	if (left redirection check)
	{
		openfd = open("file", O_RDONLY);
		if (openfd < 0)
			exit();
		dup2(openfd, STDIN_FILENO);
	}
	if (right redirection check)
	{
		if (single)
			outfd = open("file", O_WRONLY, O_CREAT, O_TRUNC);
		else
			outfd = open("file", O_WRONLY, O_CREAT, O_APPEND);
		if (outfd < 0)
			exit();
		dup2(openfd, STDOUT_FILENO);
	}
	else
	{
		dup2(fd[i - 1][READ], STDIN_FILENO);
		close (fd[i - 1][READ]);
	}
	execve("path", "cmd with option", envp);
}

void	execute_cmds(int **fd, int cmd, int i)
{
	if (i == 0)
		first_exec();
	else if (i == cmd - 1)
		last_exec();
	else
		mid_exec();
}

int main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		**fd;
	int		i; // fork 횟수
	int		status;
	int		cmd = 2;

	i = 0;
	fd = make_fd(cmd);
	while (i < 2) // 여기 들어오기 전에 here_doc 임시파일 만들기까진 되어야 ? 하는건가 ... 그렇지 싶음
	{
		if (pipe(fd[i]) == -1)
			exit (1); // pipe 실패
		pid = fork();
		if (pid == 0)
			break ;
		close (fd[i][WRITE]); // 부모 WRITE 닫기
		i++;
	}
	waitpid (pid, &status, 0); // 마지막 프로세스 기다리기
	if (pid == 0)
		excute_cmds(fd, cmd, i); // 자식만 들어가야함
	close_fd(fd);
	while (cmd)
		wait(&status); // 마지막 cmd 종료 상태 받아오기
	return (status >> 8 && 0x000000ff);
}