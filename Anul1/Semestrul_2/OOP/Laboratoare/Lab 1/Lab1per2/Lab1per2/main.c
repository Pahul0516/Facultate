// Descompune un numar natural par, mai mare strict ca 2, intr-o suma de doua numere prime

#include <stdio.h>

/// <summary>
/// functia prim primeste un parametru si veridfica daca numarul este prim
/// </summary>
/// <param name="nr"></param>
/// <returns></returns>
int prim(int nr)
{ 
    if (nr >= 2) {
        for (int d = 2; d * d <= nr; d++) {
            if (nr % d == 0)
                return 0;
        }
        return 1;
    }
    else {
        return 0;
    }
}


/// <summary>
/// functia primeste 2 parametrii si returneaza cmmdc-ul dintre cele doua
/// </summary>
/// <param name="nr1"></param>
/// <param name="nr2"></param>
/// <returns></returns>
int cmmdc(int nr1, int nr2)
{
    int r;
    while (nr2 != 0)
    {
        r = nr1 % nr2;
        nr1 = nr2;
        nr2 = r;
    }
    return nr1;
    return 0;
}

int main() {
    int nr, aux, cerinta;
    scanf_s("%d", &cerinta);
    if (cerinta == 1)
    {
        scanf_s("%d", &nr);
        while (nr != 0) {
            for (int i = 2; i <= nr - 2; i++) {
                if (prim(i) == 1) {
                    aux = nr - i;
                    if (prim(aux) == 1)
                        break;
                }
            }
            printf("%d+%d=%d\n", nr - aux, aux, nr);
            scanf_s("%d", &nr);
        }
    }
    else
    {
        int contor = 0, ok;
        for (int i = 3; i <= 10000; i++)
        {
            ok = 1;
            for (int j = 2; j <= i; j++)
            {
                if (cmmdc(i, j) == 1)
                {
                    if (prim(j) == 0)
                    {
                        ok = 0;
                    }
                }
            }
            if (ok == 1)
            {
                printf("%d ", i);
                contor = contor + 1;
            }
            if (contor == 10)
                break;
        }

    }
    return 0;
}
