#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int fd[2];
    // fd[0] - read
    // fd[1] - write
    if (pipe(fd)==-1)
    {
        printf("cea nu e bine");
    }
    int id = fork();
    if (id == 0)
    {
        close(fd[0]);
        int x;
        printf("Da-mi un numar: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    else 
    {
        close(fd[1]);
        int y; 
        read(fd[0],&y,sizeof(int));
        close(fd[0]);
        printf("Numarul citit de copil este %d\n", y);
    }
    return 0;
}
