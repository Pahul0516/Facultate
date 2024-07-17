#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int id = fork();

	if (id == -1)
		return 1;

	if (id == 0)
	{
		int file = open("de_scris", O_RDWR | O_TRUNC | O_CREAT);
		if (file == -1)
			return 1;
		
		dup2(file,STDOUT_FILENO);
		close(file);
		if (execlp("ls", "ls", NULL)==-1)
			return 1;
	}
	else 
	{
		wait(NULL);
		printf("S-a facut scrierea in fisier\n");
	}
	return 0;
}
