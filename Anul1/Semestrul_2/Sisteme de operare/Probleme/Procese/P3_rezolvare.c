#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char* argv[])
{
    char *params[] = {
        "man",
        "ls",
        NULL
    };
    execvp("man",params);
    // sau 
    //execlp("man", "man", "ls", NULL);
    return 0;
}
