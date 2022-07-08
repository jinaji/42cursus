#include "pipexx.h"

int main (int ac, char **av, char **envp)
{
	char *ag[] = {"awk", "\"{count++} END {print count}\"", 0};

	execve("/usr/bin/awk", ag, envp);
}