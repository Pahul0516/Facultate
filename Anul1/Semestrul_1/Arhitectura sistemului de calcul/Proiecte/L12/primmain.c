#include <stdio.h>

int is_prime(int a);

int main()
{
    int dim = 0; //dimensiunea vect
    int a;

    scanf("%d", &dim);

    //citire si afisare elem care sunt prime
    
    for (int i=1 ; i<=dim ; i++)
    {
        scanf("%d", &a);
        if (is_prime (a))
        {
            printf("%d \n", a);
        }
    }
    return 0;
}

  // structura stivei dupa apel is_prime:
        //EBP + 0 - val anterioare din ebp
        //EBP + 4 - adresa de retur
        //EBP + 8 - val lui A
 