#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        perror("Numarul de argumente nu e bun");
    }

    int nr;
    nr = atoi(argv[1]);

    for (int i=0;i<nr;i++)
    {
        int pid = fork();
        if (pid == -1)
        {
            perror("Fork error");
        }
        if (pid == 0) // child
        {
            printf("Child: %d -PID, %d -PPID\n", getpid(),getppid());
        }
        else 
        {
            printf("Parent: %d -PID, Child PID is %d\n", getpid(), pid);
        }
    }
    for (int i=0;i<nr;i++)
         wait(0);
    return 0;
}
