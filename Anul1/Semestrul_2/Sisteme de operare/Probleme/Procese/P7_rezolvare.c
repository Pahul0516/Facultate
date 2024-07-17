#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char* argv[])
{
     int arr[] = { 1, 2, 3, 4, 1, 2, 7, 7};
    int n = sizeof(arr) / sizeof(int); // sizeof(arr) - imi da numarul de biti din array si daca il divid cu nuamrul de biti dintr-un int obtin lungimea array-ului
    int fd[2];
    int start, end;
    if (pipe(fd) == -1)
    {
        return 1;
    }
    
    int id = fork();
    if (id == -1)
        return 2;
    
    if (id==0)
    {
        start = 0;
        end = n / 2;
    }
    else 
    {
        start = n / 2;
        end = n;
    }
    int sum = 0;
    int i;
    for (i=start;i<end;i++)
    {
        sum+=arr[i];
    }
    printf("S-a calculat suma partiala: %d\n", sum);
    if (id == 0)
    {
        close(fd[0]);
        write(fd[1],&sum,sizeof(int));
        close(fd[1]);
    }
    else
    {
        int suma_copil;
        close(fd[1]);
        read(fd[0],&suma_copil,sizeof(int));
        close(fd[0]);
        sum = sum + suma_copil;
        printf("Suma este %d\n", sum);
        wait(NULL);
    }
    return 0;
}
