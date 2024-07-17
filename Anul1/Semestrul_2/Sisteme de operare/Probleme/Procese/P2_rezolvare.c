#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

void semnal(int sgn)
{
    const char* hint = "Hint: Vezi ca 3*6 ii 18!\n";
    write(STDOUT_FILENO, hint, strlen(hint));
}

int main(int argc, char* argv[])
{
    int pid = fork();
    if (pid == -1)
        return 1;
    if (pid == 0) // child
    {
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else
    {
        signal(SIGUSR1, semnal);
        int x;
        printf("Care este rezultatul calculului 3*7?\n");
        scanf("%d", &x);
        if (x == 21)
        {
            printf("Right\n");
            kill(pid, SIGKILL);
        }
        else
        {
            printf("Wrong\n");
            kill(pid, SIGKILL);
        }
        wait(0);
    }
    return 0;
}
