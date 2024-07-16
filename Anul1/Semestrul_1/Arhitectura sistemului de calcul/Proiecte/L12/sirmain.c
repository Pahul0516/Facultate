#include <stdio.h>
#include <string.h>
// declaram functiile care se vor implementa in .asm
char elementemici(int n,char s[]);
char elementemari(int n,char s[]);

//declaram 2 siruri globale
char rez1[]="0";
char rez2[]="0";

int main()
{
    // declaram variabilele
    char s[100];
    int n,m;
    
    // introducem de la tastatura sirul
    printf("Introduceti sirul ");
    gets(s);
    n=strlen(s);

    // apelam functiile scrise in limbaj de asamblare si afisam sirurile cerute
   
   m=elementemici(n, s);
   printf("Sirul format din litere mici : %s", rez1);
  
           printf("\n");
           
    
    m=elementemari(n, s);
    printf("Sirul format din litere mari : %s", rez2);
   
            printf("\n");
    return 0;
}
