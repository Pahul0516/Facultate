#include <stdio.h>

#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(linker, "/INCLUDE:_printf")

void inversare(char sir[50]);

int main()
{
    int n=0,i=0,z=0;
    char sir[50];
    char cuv[50],inv[50];
    printf("Va rog sa introduceti o propozitie: ");
    scanf("%[^\n]",sir);
    printf("%s\n",sir);
    while (sir[n]!='\0')
    {
        n++; // calculez lungimea sirului
    }
    printf("Lungimea sirului este %d\n", n);
    sir[n]=' ';
    while (i!=n+1)
    {
        if (sir[i]!=' ')
        {
            cuv[++z]=sir[i]; // creez cuvantul care o sa fie inversat
            i++;
        }
        else
        {
            cuv[z+1]='\0';
            inversare(cuv); // apelez functia de inversare din modulul asm
            i++;
            z=0;
        }
    }

    return 0;
}
