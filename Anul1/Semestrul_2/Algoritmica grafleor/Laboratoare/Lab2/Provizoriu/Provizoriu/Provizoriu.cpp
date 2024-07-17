#include <iostream>
#include <fstream> 

using namespace std;

ifstream f("graf.txt");

struct ceva{
    int nod;
    int pondere;
};

int parinte[100], drum[1000];
int coada_prioritati[100];
ceva muchii[100][100];

void initializare(int n, int nod)
{
    for (int i = 0; i < n; i++)
    {
        drum[i] = 9999;
    }
    drum[nod] = 0;
}

int main()
{
    int n, m, nod, lungime = 0;
    int nod1, nod2, pondere;
    f >> n >> m >> nod;
    for (int i = 1; i <= m; i++)
    {
        f >> nod1 >> nod2 >> pondere;
        ceva elem;
        elem.nod = nod2;
        elem.pondere = pondere;
        muchii[nod1][i] = elem;
    }
    coada_prioritati[nod] = 0;
    lungime++;
    while(lungime != 0)
    {

    }
    return 0;
}