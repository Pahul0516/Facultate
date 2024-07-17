#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    int pid = fork();
    if (pid == -1)
        return 1;
    printf("\n");
    if (pid == 0) // sunt in copil 
    {
        int i = 1;
        printf("Acestea sunt secundele numarate de copil: ");
        while (1)
        {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
            i++;
        }
    }
    else{
        int t;
        kill(pid,SIGSTOP);
        do 
        {
            printf("\nCate secunde ii permiti copilului sa numere: ");
            scanf("%d", &t);

            if (t>0)
            {
                kill(pid,SIGCONT);
                sleep(t);
                kill(pid,SIGSTOP);
            } 
        }while(t>0);

        kill(pid,SIGKILL);
        wait(NULL);

    }
    return 0;
}
