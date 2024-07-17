#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        perror("Numar de argumente invalid");
    }
    
    int nr = atoi(argv[1]);

    int pid = fork();
    if (pid!=0) // the parent of all childrens
    {
        printf("PID -- %d\n", getpid());
    }
    for (int i=0;i<nr;i++)
    {
        if (pid == 0) // child
        {
            printf("PID -- %d PPID -- %d\n", getpid(),getppid());
            pid = fork();
        }
    }
    for (int i=0;i<=nr;i++)
        wait(0);
    return 0;
}
